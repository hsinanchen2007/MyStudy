    对于本题而言，数组只是一个辅助理解的工具。
大致要求：**质数只能放在索引（由样例得知此处的索引从 1 开始计数）为质数的位置上**。
即，对于一个确定的正整数 n，在 1 ~ n 范围内的任何一个质数，其所能放置的位置数量是一定的，有多少个质数就有多少个位置。（**设有prime个质数**）
同理，范围内非质数的位置也是确定的，即 **n - prime** 个。
接下来就是简单的排列组合问题，结果为 **prime! * (n - prime)!** ，return 时注意数据大小即可。

```
class Solution {
    public int numPrimeArrangements(int n) {
        if(n <= 2) return 1;
        int prime = 2;
        for(int i = 4;i <= n;i++) {
            if(isPrime(i) == true) prime++;
        }
        return (int)(calculate(prime) * calculate(n - prime) % 1000000007);
    }

    private boolean isPrime(int n) {
        for(int i = 2;i <= Math.sqrt(n);i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    private long calculate(int n) {
        long res = 1;
        for(int i = 2;i <= n;i++) {
            res *= i;
            res %= 1000000007;
        }
        return res;
    }
}
```
