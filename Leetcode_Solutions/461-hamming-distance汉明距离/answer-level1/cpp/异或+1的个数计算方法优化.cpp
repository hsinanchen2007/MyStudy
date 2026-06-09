# 解题思路
异或后优化1的个数的计算方法，循环次数从最左边的1出现的位数优化至1的个数。
# 代码
```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x ^ y;
        int ans = 0;
        while (a != 0) {
            ans++;
            a &= a - 1;
        }
        return ans;
    }
};
```