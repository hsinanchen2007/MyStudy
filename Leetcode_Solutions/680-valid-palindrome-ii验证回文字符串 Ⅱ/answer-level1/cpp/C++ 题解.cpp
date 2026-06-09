### 代码

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r && s[l] == s[r]) {
            ++l;
            --r;
        }
        if (l >= r) return true;
        if (l < r) {
            int l1 = l + 1;
            int r1 = r;
            while (l1 < r1 && s[l1] == s[r1]) {
                ++l1;
                --r1;
            }
            if (l1 >= r1) return true;
            int l2 = l;
            int r2 = r - 1;
            while (l2 < r2 && s[l2] == s[r2]) {
                ++l2;
                --r2;
            }
            if (l2 >= r2) return true;
        }
        return false;
    }
};
```

![image.png](https://pic.leetcode-cn.com/3f6b90dd3405279c82c58adab17055351d5874295f5987df6a68a39caff4e891-image.png)
