![图片.png](https://pic.leetcode-cn.com/3b2faa80d037841c8b0fff815ca2f25d2ce0235998f9df5e7dce220ec189ab87-%E5%9B%BE%E7%89%87.png)


1. 质数个数： [*204. 计数质数*](https://leetcode-cn.com/problems/count-primes/)
2. 优化解法： [*204. 题解 - Java简洁版*](https://leetcode-cn.com/problems/count-primes/solution/javajian-ji-ban-e-la-duo-sai-shai-fa-guan-fang-yon/)

```java
class Solution {
    public int numPrimeArrangements(int n) {
        if (n < 3)
            return 1;
        
        int count = 0;
        boolean[] nums = new boolean[n + 1];
        for (int i = 2; i * i < nums.length; i++) {
            if (!nums[i]) {
                for (int j = i * i; j < nums.length; j += i) {
                    if (nums[j])
                        continue;
                    nums[j] = true;
                    count++;
                }
            }
        }
        // 非质数的数量(加1：元素1不包含在内)
        count++;

        // 8以内的质数个数多于非质数
        if (n < 8)
            count = n - count;

        // 结果
        long res = 1;
        for (int i = 2; i <= count; i++) {
            res = (res * i) % 1000000007;
            // 这里判断会减少一轮遍历
            if (i == n - count) {
                res = (res * res) % 1000000007;
            }
        }
        return (int) res;
    } 
}
```
