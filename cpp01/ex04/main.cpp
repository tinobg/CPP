#include <iostream>
#include <fstream>
#include <string>

void replaceOccurences(std::string &content, const std::string &s1, const std::string &s2, bool &replaced) {
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content.replace(pos, s1.length(), s2);
		pos += s2. length();
		replaced = true;
	}
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: the search string (s1) cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Could not open the file " << filename << std::endl;
		return 1;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create the output file " << filename << ".replace" << std::endl;
		infile.close();
		return 1;
	}

	std:: string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();

	bool replaced = false;
	replaceOccurences(content, s1, s2, replaced);

	outfile << content;
	if (outfile.fail()) {
		std::cerr << "Error: Problem writing to the output file " << filename << ".replace" << std::endl;
		return 1;
	}
	outfile.close();

	if (!replaced) {
		std::cout << "Info: No occurences of '" << s1 << "' were found in the file" << filename << std::endl;
	}
	return 0;
}