![image.png](https://pic.leetcode-cn.com/886fa106c2c6a9d24d14a1b9e652f10fa31fb047faa5829814b6a7f6987b3a8f-image.png)

```
//2k & (2k+1) = 2k
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if(n / 2 >= m)
            return 0;
        if(m == n)
            return m;
        if(m % 2 == 1)
            return m & rangeBitwiseAnd(m + 1, n);
        return 2 * rangeBitwiseAnd(m / 2, n / 2);
    }
}
```
