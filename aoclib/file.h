#pragma once

#include <iostream>
#include <fstream>
#include <vector>

int readNumber(std::istream& stream)
{
	constexpr size_t maxLineSize = 256;
	char line[maxLineSize];
	stream.getline(line, maxLineSize);
	if (strcmp(line, "") == 0 || strcmp(line, "\0") == 0)
	{
		throw std::exception("Line was empty or null character");
	}
	int number = atoi(line);
	return number;
}

std::vector<int> readInput(const char* filename)
{
	std::fstream inputStream;
	inputStream.open(filename, std::ios_base::in);

	std::vector<int> numbers;
	while (!inputStream.eof())
	{
		try
		{
			numbers.push_back(readNumber(inputStream));
		}
		catch (std::exception)
		{
			// read an empty string, probably an empty last line of file
		}
	}

	return numbers;
}

std::string readID(std::istream& stream)
{
	constexpr size_t maxLineSize = 256;
	char line[maxLineSize];
	stream.getline(line, maxLineSize);
	return std::string(line);
}

std::vector<std::string> readIDs(const char* filename)
{
	std::fstream inputStream;
	inputStream.open(filename, std::ios_base::in);

	std::vector<std::string> ids;
	while (!inputStream.eof())
	{
		ids.push_back(readID(inputStream));
	}

	return ids;
}

