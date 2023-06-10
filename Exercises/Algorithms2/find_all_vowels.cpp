#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void FindAllVowels(const std::string& str)
{
	const string VOWELS("aeiou");

	auto start = begin(str);

	int counter = 0;

	while (start != end(str))
	{
		start = find_first_of(start, end(str), begin(VOWELS), end(VOWELS));

		if (start != end(str))
		{
			cout << "Found vowel " << *start << " at index " << distance(begin(str), start) << " of the string." << endl;
			++counter;
			++start;
		}
	}

	if (!counter)
	{
		cout << "Found no vowels in the string \"" << str << "\"." << endl;
	}
	else
	{
		cout << "Found " << counter << " vowels in the string \"" << str << "\"." << endl;
	}
}

void FindAllAdjacent(const std::string& str)
{
	auto start = begin(str);

	int counter = 0;

	while (start != end(str))
	{
		start = adjacent_find(start, end(str));

		if (start != end(str))
		{
			cout << "Found adjacent " << *start << " at index " << distance(begin(str), start) << " of the string." << endl;
			++counter;
			++start;
		}
	}

	if (!counter)
	{
		cout << "Found no adjacent equal values in the string \"" << str << "\"." << endl;
	}
	else
	{
		cout << "Found " << counter << " adjacent equal values in the string \"" << str << "\"." << endl;
	}
}

void FindAllAdjacentN(const std::string& str, int n, char val)
{
	auto start = begin(str);

	int counter = 0;

	while (start != end(str))
	{
		start = search_n(start, end(str), n, val);

		if (start != end(str))
		{
			cout << "Found " << n << " adjacent " << "\'" << val << "\' at index " << distance(begin(str), start) << " of the string." << endl;
			++counter;
			++start;
		}
	}

	if (!counter)
	{
		cout << "Couldn't find " << n << " adjacent \'" << val << "\' in the string \"" << str << "\"." << endl;
	}
	else
	{
		cout << "Found " << n << " adjacent \'" << val << "\' " << counter << " times in the string \"" << str << "\"." << endl;
	}
}

void FindAllNeedlesInHaystack(const std::string& haystack, const std::string& needle)
{
	auto start = begin(haystack);

	int counter = 0; 

	while (start != end(haystack))
	{
		start = search(start, end(haystack), begin(needle), end(needle));

		if (start != end(haystack))
		{
			cout << "Found \"" << needle << "\" in haystack at index " << distance(begin(haystack), start) << " of the string." << endl;
			++counter;
			++start;
		}
	}

	if (!counter)
	{
		cout << "Couldn't find any \"" << needle << "\" sequences in the string \"" << haystack << "\"." << endl;
	}
	else
	{
		cout << "Found \"" << needle << "\" sequence " <<  counter << " times in the string \"" << haystack << "\"." << endl;
	}
}

int main(void)
{
	FindAllVowels("");
	FindAllVowels("aaaaaaaaaaaaaaaaaaaaaaa");
	FindAllVowels("htgnhtgnhtggnh");
	FindAllVowels("Hi there, would you like to sign my petition?");
	FindAllAdjacent("");
	FindAllAdjacent("aaaaaaaaaaaaaaaaaaaaaaa");
	FindAllAdjacent("Hi there, would you like to sign my petition?");
	FindAllAdjacent("htgnhtgnhtggnh");
	FindAllAdjacentN("", 5, 'a');
	FindAllAdjacentN("aaaaaaaaaaaaaaaaaaaaaaa", 5, 'a');
	FindAllAdjacentN("htgnhtgnhtggnh", 5, 'a');
	FindAllNeedlesInHaystack("", "ht");
	FindAllNeedlesInHaystack("aaaaaaaaaaaaaaaaaaaaaaa", "ht");
	FindAllNeedlesInHaystack("htgnhtgnhtggnh", "ht");
}