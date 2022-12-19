### 解题思路
比较标准的试探回溯法。
1.pos表示digits的位置，每一次backtrace选择一个字符；
2.string支持push_back()和pop_back()的用法。
### 代码

```cpp
class Solution {
public:
    vector<string> res ;
    vector<string> str = {"abc", "def", "ghi","jkl", "mno",
            "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
        string path = "";
        int pos = 0;
        backTrace(digits, pos, path);
        return res; 
    }

    void backTrace(string& digits, int pos, string path)
    {
        if(pos == digits.size())
        {
            res.push_back(path);
            return ;
        }

        for(int i = 0; i < str[digits[pos] - '0' - 2].size(); i++)
        {
            path += str[digits[pos] - '0' - 2][i];
            backTrace(digits, pos + 1, path);
            path.pop_back();
        }
    }
};
```