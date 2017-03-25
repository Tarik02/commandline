#include "commandline/CommandLine.h"

namespace commandline {
	CommandLine::CommandLine(const std::vector <std::string> &argv) :
		argv(argv) {
		it = this->argv.begin() + 1;
	}

	CommandLine::CommandLine(int argc, char *argv[]) :
		argv() {
		this->argv.reserve((unsigned long)argc);

		do {
			this->argv.emplace_back(*argv);
			++argv;
		} while (--argc);

		it = this->argv.begin() + 1;
	}

	bool CommandLine::available() const {
		return it != argv.end();
	}

	bool CommandLine::param(const std::string &longName, char shortName) {
		if (!available()) {
			return false;
		}

		const auto &arg = *it;

		if (shortName != '\0') {
			if ((arg.size() == 2) && (arg[1] == shortName)) {
				++it;
				return true;
			}
		}

		if ((arg.size() > 2) && (arg.substr(2) == longName)) {
			++it;
			return true;
		}

		return false;
	}

	bool CommandLine::next(std::string &param) {
		if (!available()) {
			return false;
		}

		param = *it;
		++it;
		return true;
	}
}