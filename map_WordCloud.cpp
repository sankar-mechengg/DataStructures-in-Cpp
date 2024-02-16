// This program does the following
// 1. Read a text file and stores each string in a vector
// 2. Sorts the vector
// 3. Uses a map to count the number of times each string occurs
// 4. Prints the strings and their counts as a word cloud

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

// Function to convert a string to lowercase
string toLower(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

//================================================================================================

// Function to read a file and store each string in a vector
void readFile(vector<string> &v, string filename)
{
    ifstream file;
    file.open(filename);
    if (file.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    string word;
    while (file >> word)
    {
        v.push_back(word);
    }
    file.close();
}

//================================================================================================

// Function to sort the vector
void sortVector(vector<string> &v)
{
    sort(v.begin(), v.end());
}

//================================================================================================

// Function to count the number of times each string occurs
void countWords(vector<string> &v, map<string, int> &m)
{
    for (int i = 0; i < v.size(); i++)
    {
        m[toLower(v[i])]++;
    }
}

//================================================================================================

// Function to print the strings and their counts as a word cloud
void printWordCloud(map<string, int> &m)
{
    cout << "Word Cloud" << endl;
    cout << "----------" << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << setw(15) << left << it->first << it->second << endl;
    }
}

//================================================================================================

// Function to remove punctuation from a string
string removePunctuation(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]) || s[i] == ' ') // if the character is a letter or a space. isalpha() is a function that checks if a character is a letter
        {
            result += s[i];
        }
    }
    return result;
}

//================================================================================================

int main()
{
    vector<string> v;
    map<string, int> m;
    string filename = "word_cloud.txt";
    readFile(v, filename);
    sortVector(v);
    // remove punctuation
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = removePunctuation(v[i]);
    }
    countWords(v, m);
    printWordCloud(m);
    return 0;
}