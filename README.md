# Compound Word 

## Overview
The **Compound Word Finder** program identifies the longest and second longest compound words from a list of words provided in a text file. A compound word is defined as a word that can be constructed by concatenating shorter words from the same list. The program reads the input file, processes the words, and outputs the results along with the time taken to process the file.

## Design Decisions and Approach

### Data Structures
- **unordered_set**
- **unordered_set**

### Algorithm
- **isCompoundWord**: A recursive function with memoization to check if a word can be formed by concatenating other words in the set.
- **processWordList**: Reads the input file, identifies compound words, and determines the longest and second longest compound words.

## Steps to Execute the Code

### Compile the Code
Open a terminal and navigate to the directory containing the `compoundWord.cpp` file. Run the following command to compile the code:

```bash
g++ compound.cpp -o Compound
 ```
## Run the Program
Execute the compiled program with the following command:

```
./Compound
```
