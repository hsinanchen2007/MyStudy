### 解题思路

![leetcode.jpg](https://pic.leetcode-cn.com/268ce9d5a0f7c862259fae17957fe1efe1d2a4296fa1f9806896cc96292fcd8d-leetcode.jpg)


### 代码

```cpp
class Solution {
private:
        unordered_map<char, string> ump = {{'2', "abc"}, {'3', "def"}, 
                                            {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                                            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
    void dfs(int index, string & digits, string & str, vector<string> & res) {
        if(index == digits.length()) {
            res.push_back(str);
            return;
        }

        string digtStr = ump[digits[index]];
        for(int i = 0; i < digtStr.length(); i++) {
            str.push_back(digtStr[i]);
            dfs(index + 1, digits, str, res);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0) return res;

        string str;
        dfs(0, digits, str, res);

        return res;
    }
};
```