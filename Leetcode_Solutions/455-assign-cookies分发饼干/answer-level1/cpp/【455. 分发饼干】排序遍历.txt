### 思路一：暴力

### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < g.size(); ++i) {
            for (; j < s.size();) {
                if (s[j++] >= g[i]) {
                    ++res;
                    break;
                }
            }
            if (j == s.size()) break;
        }
        return res;
    }
};
```

### 另一种写法
```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= g[j]) {
                ++res;
                ++j;
                if (j == g.size()) break;
            }            
        }
        return res;
    }
};
```
