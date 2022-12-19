### 解题思路
 每次固定一个字符为一部分，其他字符为另一部分，再将固定字符与其他字符进行交换，依次遍历每个字符，再进行回溯递归。

### 代码

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        set<string> set;
        backtrack(s, 0, set);
        return vector<string>(set.begin(), set.end());

    }

    void backtrack(string s, int start, set<string> &set) {
        if (start == s.size()) {
            set.insert(s);
        }
        for (int i = start; i < s.size(); ++i) {
            swap(s[i], s[start]);
            backtrack(s, start + 1, set);
            swap(s[i], s[start]);
        }
    }
};
```