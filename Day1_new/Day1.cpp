// AdventOfCode2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <aoclib/file.h>

#include <vector>
#include <set>
#include <iostream>
#include <fstream>

int resultingFrequency(std::vector<int> changes)
{
	int result = 0;
	for (int change : changes)
	{
		result += change;
	}
	return result;
}

int firstRepeatedFrequency(std::vector<int> changes)
{
	// cache frequencies we've seen and check to see if each new one exists already
	// optimization ideas: use a dictionary; sort list

	// sets are ordered
	std::set<int> freqHistory;
	int currentFrequency = 0;
	for (auto delta = changes.begin(); ; ++delta)
	{
		// loop back to start of changes
		if (delta == changes.end())
		{
			delta = changes.begin();
		}

		freqHistory.insert(currentFrequency);
		currentFrequency += *delta;
		if (freqHistory.find(currentFrequency) != freqHistory.end())
		{
			return currentFrequency;
		}
	}

	return 0;
}

int main()
{
	std::vector<int> numbers = readInput("C:\\projects\\AdventOfCode2018\\1\\input.txt");

	int resultFreq = 0;
	resultFreq = resultingFrequency(numbers);
	std::cout << resultFreq << std::endl;

	int firstRepeatedFreq = firstRepeatedFrequency(numbers);
	std::cout << firstRepeatedFreq << std::endl;

	int input;
	std::cin >> input;

	return 0;
}

