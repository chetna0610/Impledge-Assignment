#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <chrono>
#include <queue>

using namespace std;

set<string> wordSet;
map<string, bool> memo;

bool canFormWord(const string &word, const set<string> &wordSet)
{
    if (wordSet.empty())
        return false;
    if (memo.find(word) != memo.end())
        return memo[word];

    vector<bool> dp(word.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= word.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (dp[j] && wordSet.find(word.substr(j, i - j)) != wordSet.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    memo[word] = dp[word.size()];
    return dp[word.size()];
}

void processWordList(const string &inputFileName)
{
    auto startTime = chrono::high_resolution_clock::now();

    // Clear previous data
    wordSet.clear();
    memo.clear();

    // Read words from input file
    ifstream inputFile(inputFileName);
    string word;
    vector<string> allWords;

    while (inputFile >> word)
    {
        wordSet.insert(word);
        allWords.push_back(word);
    }
    inputFile.close();

    // Priority queue to store compound words sorted by length
    vector<pair<int, string>> compoundWordsByLength;

    // Identify all compound words
    for (const string &word : allWords)
    {
        wordSet.erase(word); // Temporarily remove the word to avoid using itself
        if (canFormWord(word, wordSet))
        {
            compoundWordsByLength.push_back({word.length(), word});
        }
        wordSet.insert(word); // Reinsert the word back into the set
    }

    // Extract the two longest compound words
    string longestCompoundWord = "";
    string secondLongestCompoundWord = "";

    if (!compoundWordsByLength.empty())
    {
        longestCompoundWord = compoundWordsByLength.back().second;
        compoundWordsByLength.pop_back();

        if (!compoundWordsByLength.empty())
        {
            secondLongestCompoundWord = compoundWordsByLength.back().second;
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto processingTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    // Display results
    cout << "Results for " << inputFileName << ":\n";
    cout << "Longest Compound Word: " << longestCompoundWord << "\n";
    cout << "Second Longest Compound Word: " << secondLongestCompoundWord << "\n";
    cout << "Processing Time: " << processingTime.count() << " milliseconds\n\n";
}

int main()
{
    // Process both input files
    processWordList("Input_01.txt");
    processWordList("Input_02.txt");

    return 0;
}