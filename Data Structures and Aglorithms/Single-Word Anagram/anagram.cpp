/*
 * Name:
 * Date Submitted:
 * Assignment Name:
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);
void mergeSortHelper(vector<char>& list, int l, int r);
void merge(vector<char>& list, int l, int m,int r);
string mergeSort(string word);

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    //create a unordered_map to hash wordlist to
    unordered_map<string, int> map;
        hash<string> hash;
        int hashIndex;
        for(auto str : wordlist)
        {
            hashIndex = (int)hash(str) % wordlist.size();
            map.insert({str,hashIndex});
        }
        
 

    vector<string> anagrams;
    
    //create new string that contains the word's letters in alphabetical order
    string w = word;
    string wordAlphabetical = mergeSort(w);;

   
    bool foundWord = false;
    
    // iterates through the whole map of words
    unordered_map<string, int>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
        string str = it->first; // gets the string variable in the map
        if(str == word && foundWord == false) // adds repeated word to the anagrams vector
        {
            anagrams.push_back(word);
            foundWord = true;
        }
        if(str != word)
        {
            str = mergeSort(str); // converts current string into alphebetical order to compare with wordAlphabetical
            if (str == wordAlphabetical) // if the two strings are the same, push it into the vector
                anagrams.push_back(it->first);
        }
    }
    
    return anagrams;
}

 // my mergsort algorithm from Lab 4 modified to sort a vector<chars> and returns the sorted value as a string

void mergeSortHelper(vector<char>& word, int l, int r){ // recursively breaks down array untill 1 element in each

    if(l < r){
        int mid = (r+l)/2;
        mergeSortHelper(word, l, mid);
        mergeSortHelper(word, mid+1, r);
        merge(word, l, mid, r);
    }
    return;
}

void merge(vector<char>& word, int l, int m,int r){ // puts back each smaller array back into list array
    int leftSize = m-l+1; // size of left array
    int rightSize = r-m;   // size of right array

        std::vector<char> left;
        std::vector<char> right;

        //temp partition into left and right subarrays
        for (int i = 0; i < leftSize; i++)
            left.push_back(word[l+i]);
        for (int j = 0; j < rightSize; j++)
            right.push_back(word[m+1+j]);

        
        int lIndex = 0;
        int rIndex = 0;
        int i = l;

        while (lIndex < leftSize && rIndex < rightSize)
        {
            if (left[lIndex] <= right[rIndex])
            {
                word[i] = left[lIndex];
                lIndex++;
            }
            else
            {
                word[i] = right[rIndex];
                rIndex++;
            }
            i++;
        }

        // Copy the remaining elements of left
        while (lIndex < leftSize)
        {
            word[i] = left[lIndex];
            lIndex++;
            i++;
        }

        // Copy the remaining elements of right
        while (rIndex < rightSize)
        {
            word[i] = right[rIndex];
            rIndex++;
            i++;
        }
    return;
}



string mergeSort(string word){
    
    vector<char> vectorWord;

    for(int i = 0; i < word.size(); i++){
        char temp = word.at(i);
        vectorWord.push_back(temp);
    }
    mergeSortHelper(vectorWord,0,(int)vectorWord.size()-1);
    string str;
    for(int i = 0; i < vectorWord.size(); i++){
        str += vectorWord[i];
    }
    return str;
}
