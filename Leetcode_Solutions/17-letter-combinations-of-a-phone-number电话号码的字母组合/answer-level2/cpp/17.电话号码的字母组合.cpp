### 解题思路
递归

### 代码

```cpp
class Solution {
public:
    vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        func(res, "", digits, 0);
        return res;
    }
    void func(vector<string> &res, string str, string &digits, int i)
    {
        if(i >= digits.size())
        {
            if(str.size() > 0) 
            {
                res.push_back(str);
            }
            return;
        }
        else
        {
            string s = table[digits[i] - '2'];
            for(int j = 0; j < s.size(); ++j)
            {
                str.push_back(s[j]);
                func(res, str, digits, i+1);
                str.pop_back();
            }
        }
    }
};
```