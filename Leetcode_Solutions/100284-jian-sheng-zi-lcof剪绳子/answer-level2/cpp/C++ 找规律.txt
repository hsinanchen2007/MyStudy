### 解题思路
请参考https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/ 这篇题解
这篇题解找出了规律，就是尽量分成为3的小段。
如果余一的时候，应该将最后的1加上一段3合并为4.
如果余2的时候，再乘上2.

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) {
            return n-1;
        }
        int a = n / 3;
        int b = n % 3;
        if (b == 0) {
            return pow(3, a);
        } else if (b == 1) {
            return pow(3, a-1) * 4;
        } else {
            return pow(3, a) * 2;
        }
    }
};
```