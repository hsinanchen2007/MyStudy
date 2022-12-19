### 解题思路
当初不知道C++自带了异或操作，自己写了一个等价的表达式。应该也对。

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, ans = 0;
        res = x ^ y;//res = (~(x & y)) & (x | y);
        while (res) {
            if (res % 2 == 1)
                ans += 1;
            res /= 2;
        }
        return ans;
    }
};
```