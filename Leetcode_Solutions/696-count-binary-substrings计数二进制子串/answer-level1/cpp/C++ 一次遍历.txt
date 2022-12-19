### 解题思路
一次遍历，分别记录当前连续字符数与前一个连续字符数即可

### 代码

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++curr;
            } else {
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        res += min(prev, curr);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0f26bfda05996d3fa7f897c271d4216b6b5ff51af14f3b243a132bf555199456-image.png)
