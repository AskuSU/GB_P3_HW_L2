#pragma once
#include <vector>
#include <string>
#include <string_view>

#include "RunTimer.h"


std::vector<std::string> SplitString(const std::string& s) {
	RunTimer timer("string");
	std::vector<std::string> result;
	size_t space_pos = 0;
	while (true) {
		size_t pos = s.find(' ', space_pos);
		if (pos == s.npos) {
			result.push_back(s.substr(space_pos, s.size() - space_pos));
			break;
		}
		result.push_back(s.substr(space_pos, pos - space_pos));
		space_pos = pos + 1;
	}
	timer.print();
	return result;
}

std::vector<std::string_view> SplitStringWithSW(const std::string& s) {
	RunTimer timer("string_view");
	std::string_view sw = s;
	std::vector<std::string_view> result;
	size_t space_pos = 0;
	while (true) {
		size_t pos = sw.find(' ', space_pos);
		if (pos == sw.npos) {
			result.push_back(sw.substr(space_pos, sw.size() - space_pos));
			break;
		}
		result.push_back(sw.substr(space_pos, pos - space_pos));
		space_pos = pos + 1;
	}
	timer.print();
	return result;
}