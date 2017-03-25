#pragma once

#include <string>
#include <vector>

namespace commandline {
	class CommandLine {
	private:
		std::vector <std::string> argv;
		std::vector<std::string>::iterator it;

	public:
		CommandLine(const std::vector <std::string> &argv);
		CommandLine(int argc, char *argv[]);

		bool available();
		bool param(const std::string &longName, char shortName = '\0');
		bool next(std::string &param);
	};
}
