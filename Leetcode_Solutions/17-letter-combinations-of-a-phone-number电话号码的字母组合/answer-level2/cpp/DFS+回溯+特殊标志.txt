### 解题思路
由题目可知，2-7 对应的是abc + num*3，其中7多进了一位
从8-9 则是bcd+num*3 ，然后9多了一个z既可。

### 代码

```cpp
class Solution {
public:
    vector<string> vecResult;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return  vecResult;
        }
        Dfs(digits, 0, "");
        return  vecResult;
    }
    void Dfs(string digits, int index, string result) {
        if (index == digits.size()) {
            vecResult.push_back(result);
            return;
        }
        int num = digits[index] - '2';
        if (num >=0 && num < 5) {
            char c1 = num * 3 + 'a';
            char c2 = num * 3 + 'b';
            char c3 = num * 3 + 'c';
            Dfs(digits, index + 1, result + c1);
            Dfs(digits, index + 1, result + c2);
            Dfs(digits, index + 1, result + c3);
        }
        if (num >= 5) {
            char c1 = num * 3 + 'b';
            char c2 = num * 3 + 'c';
            char c3 = num * 3 + 'd';
            Dfs(digits, index + 1, result + c1);
            Dfs(digits, index + 1, result + c2);
            Dfs(digits, index + 1, result + c3);
        }
        if (num == 5) {
            Dfs(digits, index + 1, result + "p");
        }
        if (num == 7) {
            Dfs(digits, index + 1, result + "z");
        }
        return;
    }
};
```