1.使用stack找出回文字符集合
2.DFS回溯搜索
```
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> results;
        if (canPermutePalindrome(s)) {
            vector<bool> visited(choices.size(), false);
            generatePalindromesDfs(-1, "", visited);
            copy(halfs.begin(), halfs.end(), back_inserter(results));
            
            for (int i = 0; i < results.size(); ++i) {
                string reverseString = results[i];
                reverse(reverseString.begin(), reverseString.end());
                results[i] = results[i] + center + reverseString;
            }
        }
        return results;
    }
    
    
    void generatePalindromesDfs(int index, string result, vector<bool> visited) {
        if (index == (choices.size() - 1)) {
            halfs.insert(result);
            return;
        }

        set<string> sames;
        for (int i = 0; i < choices.size(); ++i) {
            if (visited.at(i) == true) {
                continue;
            }
            
            string newResult = result;
            newResult.push_back(choices.at(i));
            if(sames.find(newResult) == sames.end()) {
                sames.insert(newResult);
                vector<bool> newVisited = visited;
                newVisited[i] = true;
                generatePalindromesDfs(index + 1, newResult, newVisited);
            }
        }
    }
    
private: 
    bool canPermutePalindrome(string s) {
        string input = s;
        sort(input.begin(), input.end());
        
        stack<char> charStack;
        for (string::const_iterator iter = input.begin();
            iter != input.end();
            ++iter) {
            if (charStack.empty()) {
                charStack.push(*iter);
                continue;
            }
            char current = charStack.top();
            if (current == *iter) {
                choices.push_back(*iter);
                charStack.pop();  
                continue;
            }
            charStack.push(*iter);
        }
        
        if (!charStack.empty()) {
            center.push_back(charStack.top());
        }
        return charStack.size() > 1 ? false : true;
    }
private:
    vector<char> choices;
    string center;
    
    set<string> halfs;
};
```
