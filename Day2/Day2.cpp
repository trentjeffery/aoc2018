// Day2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <aoclib/file.h>

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

// part 1

int hasMultiple(std::string s, int count)
{
	// the number of times each char in the string appears
	std::map<char, int> duplicateCounts;
	for (const char& c : s)
	{
		if (duplicateCounts.find(c) == duplicateCounts.end())
		{
			duplicateCounts[c] = 1;
		}
		else
		{
			++duplicateCounts[c];
		}
	}

	for (const auto& pair : duplicateCounts)
	{
		if (pair.second == count)
		{
			return true;
		}
	}

	return false;
}

int checksum(std::vector<std::string> ids)
{ 
	int doublesCount = 0;
	int triplesCount = 0;
	for (auto& s : ids)
	{
		if (hasMultiple(s, 2))
		{
			++doublesCount;
		}
		if (hasMultiple(s, 3))
		{
			++triplesCount;
		}
	}

	return doublesCount * triplesCount;
}

// part 2

// 1. find correct boxes (those that differ in one position)
// 2. determine which letters are common

bool idsDifferByOne(std::string id1, std::string id2)
{
	return false;
}

std::string getCommonLetters(std::string id1, std::string id2)
{
	return std::string("");
}

std::string findSharedIDLetters(std::vector<std::string> ids)
{
	std::sort(ids.begin(), ids.end());

	for (auto currentID = ids.begin(); currentID + 1 != ids.end(); ++currentID)
	{
		const std::string& id1 = *currentID;
		const std::string& id2 = *(currentID + 1);
		if (idsDifferByOne(id1, id2))
		{
			return getCommonLetters(id1, id2);
		}
	}

	return std::string("");
}


// main

int main()
{
	// Read in input
	std::vector<std::string> input = readIDs("C:\\projects\\AdventOfCode2018\\2\\input.txt");;

	int boxChecksum = checksum(input);

	std::cout << boxChecksum << std::endl;
	int waitForInput;
	std::cin >> waitForInput;

    return 0;
}

