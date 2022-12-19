### 解题思路
* 1、逐个数字读取，进行递归
* 2、找出数字对应的所有字母，逐个迭代，在迭代中循环步骤1，直到所有数字读取完。

### 代码

```cpp
class Solution {
    unordered_map<char, string> map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return vector<string>();
        string s = "";
        combinate(digits, 0, s);
        return ans;
    }
    void combinate(string digits, int pos, string letter) {
        if(pos == digits.length()) {
            ans.push_back(letter);
            return ;
        }
        char chcur = digits[pos];
        string letters = map[chcur];
        for(char c: letters) {
            combinate(digits, pos+1, letter+c);
        }
    }
};
```
![q.png](https://pic.leetcode-cn.com/26f78b910c281635be4d7c28c0cafe876d8847eef0eb17616dc4a5cd35cff521-q.png)
