### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    vector<string> phoneMap= {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
vector<string> letterRet;

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return letterRet;
        string letterComb = "";
        helper(digits,0,letterComb);
        return letterRet;
    }

    void helper(string digits,int intPos, string letterComb){
        if (intPos == (digits.size())){
                letterRet.push_back(letterComb);
                return;
        }

        string strTmp = phoneMap[digits[intPos] - '0'];
        for (int i=0;i < strTmp.size(); i++){
            char chTmp = phoneMap[digits[intPos] - '0'][i];
            letterComb.push_back(chTmp);
            helper(digits,intPos + 1, letterComb);
            letterComb.pop_back();
        }
        return;
    }
};
```