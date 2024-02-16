// This Program does the following

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

// Function to remove punctuation from a string
std::string removePunctuation(const std::string &str)
{
    std::string result;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(result), ispunct);
    return result;
}

// Function to read words from a file and store them in a set
std::set<std::string> readWordsFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::set<std::string> words;
    std::string word;
    while (file >> word)
    {
        // Remove punctuation from the word
        word = removePunctuation(word);
        // Convert word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.insert(word);
    }
    return words;
}

// Function to compute the intersection of two sets
std::vector<std::string> setIntersection(const std::set<std::string> &set1, const std::set<std::string> &set2)
{
    std::vector<std::string> intersection;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(intersection));
    return intersection;
}

// Function to compute the union of two sets with no duplicates
std::vector<std::string> setUnion(const std::set<std::string> &set1, const std::set<std::string> &set2)
{
    std::vector<std::string> unionSet;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(unionSet));
    return unionSet;
}

int main()
{
    std::string file1, file2;
    std::cout << "Enter the name of the first file: ";
    std::cin >> file1;
    std::cout << "Enter the name of the second file: ";
    std::cin >> file2;

    // Read words from the files
    std::set<std::string> words1 = readWordsFromFile(file1);
    std::set<std::string> words2 = readWordsFromFile(file2);

    // Compute the intersection of words
    std::vector<std::string> intersection = setIntersection(words1, words2);

    // Compute the union of words
    std::vector<std::string> unionSet = setUnion(words1, words2);

    // Calculate the plagiarism percentage
    double plagiarismPercentage = (double)intersection.size() / unionSet.size() * 100;

    // Print the intersection
    std::cout << "Intersection of words: ";
    for (const auto &word : intersection)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Output the plagiarism result
    std::cout << "Plagiarism Percentage: " << plagiarismPercentage << "%" << std::endl;

    return 0;
}
