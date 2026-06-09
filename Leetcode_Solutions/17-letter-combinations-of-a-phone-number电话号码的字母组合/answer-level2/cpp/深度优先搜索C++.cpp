### 解题思路
深度优先搜索套路，没啥可说的。

### 代码

```cpp
class Solution {
public:
    const vector<string> letter_map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }

        string current;
        dfs(digits, 0, current, result);
        return result;
    }

    void dfs(const string& digits, int level, string& current, vector<string>& result) {
        if (level > digits.size() - 1) {
            result.push_back(current);
            return;
        }
        for(char letter : letter_map[digits[level] - '0']) {
            current.push_back(letter);
            dfs(digits, level+1, current, result);
            current.pop_back();
        }
    }
};
```

![微信截图_20200406121215.png](https://pic.leetcode-cn.com/dff692058825a9c2ba01e1d7022953754f304b01f7a5a0d04aa98c955774cd00-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200406121215.png)
