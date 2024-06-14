#include <iostream>
#include <unordered_map>
using namespace std;
//https://www.geeksforgeeks.org/match-a-pattern-and-string-without-using-regular-expressions/
/* Function to find out if string follows a given pattern using backtracking */
bool patternMatchUtil(string str , int n , int  i , string pat ,int m ,  int j , unordered_map<char, string>&  mp) { 
    if(i == n && j == m) return true;
    if(i == n || j == m) return false;

    char ch = pat[j];
    
    //if current char is already present inside the map
    if(mp.find(ch) != mp.end()){ 
        string currstr = mp[ch];
        int len = currstr.size();

        string substr = str.substr(i,len);

        if(substr != currstr) { 
            return false;
        }else { 
            return patternMatchUtil(str,n,i + len,pat,m,j+1,mp);
        }
    }else { //no char found 
        for(int len = 1 ; len < n - i ; len ++ ){
            string substring = str.substr(i,len);

            mp[ch] = substring;

            if(patternMatchUtil(str,n,i + len,pat,m,j + 1,mp)){ 
                return true; // sol found
            }
            mp.erase(ch); 
        }
        return false;
    }   


    
}
bool patternMatch(string str, string pat, int n, int m)
{
    if (n < m)
    return false;
 
    // create an empty hashmap
    unordered_map<char, string> map;
 
    // store result in a boolean variable res
    bool res = patternMatchUtil(str, n, 0, pat, m, 0, map);
 
    // if solution exists, print the mappings
    for (auto it = map.begin(); res && it != map.end(); it++)
        cout << it->first << "->" << it->second << endl;
 
    // return result
    return res;
}

// Driver code
int main() {
    string str = "GraphTreesGraph", pat = "aba";
    int n = str.size();
    int m  = pat.size();

    if (!patternMatch(str, pat,n,m)) {
        cout << "No Solution exists" << endl;
    }

    return 0;
}
