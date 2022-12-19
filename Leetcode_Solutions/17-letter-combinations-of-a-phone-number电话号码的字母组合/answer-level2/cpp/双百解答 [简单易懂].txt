### 解题思路
![image.png](https://pic.leetcode-cn.com/23d90218f301cd1e320fd563dc01672ab38cf7810bf5b794e0ee853eb58e48e8-image.png)

这题很明显，绝对是回溯思路。
1、观察规律：
2-7对应的字母是num*3 +'a'、 num*3+'b'、 num*3+'c'。
8-9对应的字母是num*3 +'b'、num*3+'c'、num*3+'d'.
最后7和9各自多出来字符，再额外添加既可。

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