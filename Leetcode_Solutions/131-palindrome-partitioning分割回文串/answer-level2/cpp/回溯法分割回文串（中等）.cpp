### 解题思路
回溯法

### 代码

``` cpp
class Solution {
private:
    vector<vector<string>> result;
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(string s, vector<string> strs, int k, int n) {
        if (k == n) {
            result.push_back(strs);
            return;
        }
        for (int i = k + 1; i <= s.size(); i++) {
            string cur = s.substr(k, i - k);
            if (isPalindrome(cur)) {
                strs.push_back(cur);
                backtrack(s, strs, i, n);
                strs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> strs;
        backtrack(s, strs, 0, n);
        return result;
    }
};
```
