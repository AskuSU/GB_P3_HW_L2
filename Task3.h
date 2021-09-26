#pragma once
#include <algorithm>

uint16_t Count_if_find(const std::string& search_line, const std::string& search_elements)
{
	return std::count_if(search_line.begin(), search_line.end(),
		[&search_elements](const char& c)
		{
			return search_elements.find(c) != std::string::npos;
		});
}

uint16_t Count_if_for(const std::string& search_line, const std::string& search_elements)
{
	return std::count_if(search_line.begin(), search_line.end(),
		[&search_elements](const char& c)
		{
			for (const auto& search_element : search_elements)
			{
				if (c == search_element) return true;
			}
			return false;
		});
}

uint16_t For_find(const std::string& search_line, const std::string& search_elements)
{
	uint16_t count(0);
	for (const auto& c : search_line)
	{
		if (search_elements.find(c) != std::string::npos) count++;
	}
	return count;
}

uint16_t For_For(const std::string& search_line, const std::string& search_elements)
{
	uint16_t count(0);
	for (const auto& c : search_line)
	{
		for (const auto& search_element : search_elements)
		{
			if (c == search_element) 
			{
				count++;
				break;
			}
		}
	}
	return count;
}