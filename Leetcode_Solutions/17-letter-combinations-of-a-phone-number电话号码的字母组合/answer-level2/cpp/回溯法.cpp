### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   const string letterMap[10] = {
        " ", //0
        "",  //1
        "abc", //2
        "def", //3
        "ghi", //4
        "jkl", //5
        "mno", //6
        "pqrs", //7
        "tuv", //8
        "wxyz", //9
    };
    vector<string> res;
    //s中存了digits[0...index-1]字母组合,寻找和digits[index]匹配的字母，获得digits[0...index]翻译得到的解
    void dfs(const string &digits, int index, const string &s) {
        if(index == digits.size()) {
            res.push_back(s);
            return;
        }
        string letters = letterMap[digits[index]-'0'];
        for (int j = 0; j < letters.size(); j++) {
            dfs(digits, index+1, s+letters[j]);
        }
        return ;
        
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.size() == 0) {
            return res;
        }
        dfs(digits, 0, "");
        return res;
    }
};
```