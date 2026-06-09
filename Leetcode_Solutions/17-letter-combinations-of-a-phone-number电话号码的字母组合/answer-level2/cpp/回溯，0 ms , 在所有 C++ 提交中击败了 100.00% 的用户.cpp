### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s;
        int length = digits.length();
        if(length == 0)
        return ans;
        DFS(0, s, length, digits);
        return ans;
    }
    void DFS(int n, string &s, int length, string digits)
    {
        if(n == length)
        {
            ans.push_back(s);
            return ;
        }
        int index = digits[n] - '0';
        for(int i = 0 ; i < hash[index].length() ; ++i)
        {
            s += hash[index][i];
            DFS(n + 1, s, length, digits);
            s = s.substr(0, s.length() - 1);
        }
    }
private:
    vector<string> ans;
    string hash[10] = {"0", "0", "abc", "def", "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"};
};
```