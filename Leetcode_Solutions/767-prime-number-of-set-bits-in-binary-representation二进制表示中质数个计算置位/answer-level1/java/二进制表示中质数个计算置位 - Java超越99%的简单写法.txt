#### 解题思路
- `L，R` 最大为 $10^6$，转换为二进制，有 20 位，故 **计算置位** 个数不会超过 20。即求出 20 以内的质数列表即可。
- 使用 `Integer.bitCount(i)` 函数可快速求得 `i` 的二进制形式中 1 的个数。

#### 代码：
```Java [-Java]
class Solution {
   public int countPrimeSetBits(int L, int R) {
        //0-20的质数列表，prime[i]为1，则i为质数
        int[] primes = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
        int res = 0;
        for (int i = L; i <= R; i++) {
            int t = Integer.bitCount(i);
            res += primes[t];
        }
        return res;
    }
}
```
