### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
  private:
    unordered_map<char, string> dict;
    unordered_map<string, bool> visited;
  public:
    bool wordPatternMatch(string pattern, string str) {
      return dfs(pattern, str, 0, 0);
    }

    bool dfs(string pattern, string str, int start, int j) {
      if(start == str.size()) {
        if(j == pattern.size())
          return true;
        else
          return false;
      }

      if(dict.count(pattern[j]) == 0) {
        for(int i=start; i<str.size(); i++) {
          string candidate = str.substr(start, i - start + 1);
          if(visited.count(candidate) > 0)
            continue;
          dict[pattern[j]] = candidate;
          visited[candidate] = true;
          if(dfs(pattern, str, i + 1, j + 1))
            return true;
          dict.erase(pattern[j]);
          visited.erase(candidate);
        }
      } else{
        string candidate = dict[pattern[j]];
        int n = candidate.size();
        if(str.substr(start, n) != candidate)
          return false;
        // cout << candidate << " matched." << endl;
        return dfs(pattern, str, start + n, j + 1);
      }
      return false;
    }
};
```