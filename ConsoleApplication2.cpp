/*This is my most recent work for the class CS412: An Introduction to Data Warehousing and Data Mining which I am currently taking. In this program I
 implemented the Apriori algorithm and apply it to mine frequent itemsets from a real-life data set. This program will output all the length-1 frequent 
 categorie the category sets that have an absolute support larger than 771
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;


int main()
{
	std::map<string, int> mymap;
	string line;
	string line2;
	ifstream myfile;
	myfile.open("categories.txt");
	ofstream writefile;
	writefile.open("testingt.txt");
	int i = 0;
	if (myfile.is_open() && writefile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';

			stringstream ss;
			ss.str(line);
			while (getline(ss, line2, ';')) {
				std::pair<std::map<string, int>::iterator, bool> ret;
				ret = mymap.insert(std::pair<string, int>(line2, 1));
				if (ret.second == false) {
					 (ret.first->second)++;
				}

			}
			i++;
		}
		std::map<string, int>::iterator it = mymap.begin();
		while( it != mymap.end()) {
			if (it->second < 771) {			
				it = mymap.erase(it);
			}
			else { it++; }
		}


		for (it = mymap.begin(); it != mymap.end(); ++it)
		{
			int a = it->second;
			string b = it->first;
			std::cout << it->first << " => " << it->second << '\n';
	//		writefile << a <<":"<< b <<"\n";
			writefile << b << "\n";

		}

		cout << "number of lines is " << i<<endl;
		myfile.close();
		writefile.close();
	}

	else cout << "Unable to open file";

	return 0;
}


