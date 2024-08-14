#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type


unordered_map<string, bool> visited;         // have we queued up this state for visitation?
unordered_map<string, string> pred;          // predecessor state we came from
unordered_map<string, int> dist;             // distance (# of hops) from source node
unordered_map<string, vector<string>> nbrs;  // vector of neighboring states


//Implement breadth-first search, refer to Lab 10

void build_graph();

const char ALPHABET [] = {'a','b','c','d','e','f','g','h','i','j','k','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','y','x','z'};



void build_graph(){
    //input data from file into V
     ifstream fin ("wordlist05.txt");
    //ifstream fin ("/Users/seanhermes/School/Algs & Data Structures/Assignment/WordLadder/WordLadder/wordlist05.txt");
    string str;
    while(!fin.eof()){
        fin >> str;
        V.push_back(str);
    }
    
    //build graph
    for(string word : V){// loops through each word in V
        for(int i = 0; i < word.length();i++){ // loops through each letter in current word
            for(char c : ALPHABET){ // loops through each letter of alphabet
                string temp = word;
                temp.at(i) = c;
                if(temp != word){ // no repeat words
                    nbrs[word].push_back(temp); // adds words one letter away to nbrs
                }//if
            }//for
        }//for
    }//for
}

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  //Implement this function
   
    //build graph
    build_graph();
   
    //performs breadth search outwards of s
    queue<string> to_visit;
    to_visit.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (!to_visit.empty()) {
      string curnode = to_visit.front();
      to_visit.pop();
        for (string n : nbrs[curnode]){
            if (!visited[n]) {
                pred[n] = curnode;
                dist[n] = 1 + dist[curnode];
                visited[n] = true;
                to_visit.push(n);
            }
        }
    }
    
    // gets path and steps
    // repeats until start and target are the same,
    // iterates from target back using pred
    for(int i = 0; i < V.size();i++){ // loop through size to prevent infinite loop
        if(pred.find(t) == pred.end())
            break;
        if(s != t){
            steps++;
            p.push_back(t);
            t = pred[t];
        }
    }
}

//int main(void)
//{
//  int steps = 0;
//  string s = "stale";
//  string t = "tales";
//  vector<string> path;
//  
////  cout << "Source: ";
////  cin >> s;
////
////  cout << "Target: ";
////  cin >> t;
//
//  wordLadder(s, t, steps, path);
//
//  if (steps == 0)
//  {
//      cout << "No path!\n";
//  }
//  else
//  {
//      cout << "Steps: " << steps << "\n\n";
//      for (int i=0; i<path.size(); i++)
//      {
//          cout << path[i] << endl;
//      }
//  }
//  return 0;
//}


