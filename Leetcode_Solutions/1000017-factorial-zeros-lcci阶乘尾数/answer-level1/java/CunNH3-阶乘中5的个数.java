[172. 阶乘后的零](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)
10 = 5 * 2
2的个数很多无需考虑
考虑5的个数
n / 5 就是 5 的倍数的个数, 除此以外 有些5的倍数含有多个 5 的因数 比如 25 = 5*5 125 = 5*5*5
所以
5 的个数就是 n / 5 + n / 25 + n / 125 ...
```
class Solution {
    public int trailingZeroes(int n) {
        int res = 0;
        while(n != 0){
            res += n / 5;
            n /= 5;
        }
        return res;
    }
}
```
