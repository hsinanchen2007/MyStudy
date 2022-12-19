### 用 unordered_set 去重
```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        result.resize(s.size());
        vector<bool> visited(s.size(), false);
        backtrack(s, visited, 0);
        return vector<string>(results.begin(), results.end());
    }
    
private:
    void backtrack(const string &s, vector<bool> visited, int round) {
        if (round == s.size()) {
            results.insert(result);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                result[round] = s[i];
                backtrack(s, visited, round+1);
                visited[i] = false;
            }
        }
    }
    
private:
    string result;
    unordered_set<string> results;    //1
};
```

### 先把 s 排序，在每轮选择字母的时候判断去重
```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        result.resize(s.size());
        vector<bool> visited(s.size(), false);
        sort(s.begin(), s.end());    // 1
        backtrack(s, visited, 0);
        return results;
    }
    
private:
    void backtrack(const string &s, vector<bool> visited, int round) {
        if (round == s.size()) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (visited[i]) continue;
            else if (i > 0 && !visited[i-1] && s[i] == s[i-1]) continue;    // 2
            else {
                visited[i] = true;
                result[round] = s[i];
                backtrack(s, visited, round+1);
                visited[i] = false;
            }
        }
    }
    
private:
    string result;
    vector<string> results;
};
```