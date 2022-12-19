### 解题思路

### 代码

```cpp
class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            Dfs(s, i, i);
            Dfs(s, i, i + 1);
        }
        return count;
    }
    void Dfs(string s, int index1, int index2) {
        if (index1 < 0 || index2 >= s.size()) {
            return;
        }
        if (s[index1] != s[index2]) {
            return;
        }
        count++;
        index1--;
        index2++;
        Dfs(s, index1, index2);
        return;
    }
};
```