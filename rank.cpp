#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {

	std::ifstream list("list");
	std::map<std::string, int> unsorted;
	std::multimap<int, std::string> sorted;
	std::string name;

	while (getline(list, name)) {
		++unsorted[name];
	}

	for (std::map<std::string, int>::const_iterator it = unsorted.begin(); it != unsorted.end(); ++it) {
		sorted.insert(std::pair<int, std::string>(it->second, it->first));
	}

	for (std::multimap<int, std::string>::const_reverse_iterator it = sorted.rbegin(); it != sorted.rend(); ++it) {
		std::cout << it->first << "\t" << it->second << "\n";
	}

	return 0;
}
