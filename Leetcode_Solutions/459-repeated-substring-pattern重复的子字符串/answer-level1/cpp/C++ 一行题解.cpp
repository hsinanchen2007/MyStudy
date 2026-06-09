### 代码

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
```

![image.png](https://pic.leetcode-cn.com/2aacb2368f1be70cb878152898993eb6f5c3618eb9bd676a14dbba0834e74e7d-image.png)
