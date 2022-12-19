### 解题思路
利用rfind函数，要考虑到多种异常情况
![捕获.PNG](https://pic.leetcode-cn.com/8628ae5fe362e033871c708b0a9c14c6954e35521e6e9027b01eecac5c3414c6-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        while (n >= 0)
        {
            int pos = s.rfind(' ', n);
            if (pos == string::npos)
                return n + 1;
            else if (pos == n)
                --n;
            else
                return (n - pos);
        }
        return 0;
    }
};
```