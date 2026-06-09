## 1. 分析
这道题本质上是道动态规划题目，为什么这么说呢？
根据`格雷编码`的定义：
> 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

我们可以知道，数字`n-1`的格雷编码同时**也可以**作为数字`n`的格雷编码的一部分.
而且数字`n-1`的格雷编码的个数为`2^(n-1)`个，所以要找到数字`n`的格雷编码只需要再找到`2^(n-1)`个即可。

对于这另外一半的求法, 一种方法是通过对前一半（即`n-1`的格雷编码）的编码的首位加1得到：

![image.png](https://pic.leetcode-cn.com/3dac46794f63bd7a01482137a79e00596010e40f8e6c309690c98c28c5321b7a-image.png)

上图来自: [Wikipedia](https://en.wikipedia.org/wiki/Gray_code#/media/File:Binary-reflected_Gray_code_construction.svg)

如上图n=3的格雷编码的前一半取自n=2, 后一部分以上图中的水平线做镜像操作，在首位加1.

## 2. DP推导

我们定义数字n的格雷编码为`dp[n]`, 期中`dp[n][i]`为n的格雷编码的第i个，显然dp要是个二维数组，而且每一行的个数还不一样。dp[n]中i的范围为 : `[0, 2^n)`, 我们定义`N`为数字n的格雷编码的总个数. 

**状态转移方程:**
```
            dp[n-1][i]         (0 <= i < N/2)
dp[n][i] = 
            dp[n][N - 1 - i]   (N/2 <= i < N)
```

代码如下：

```java
class Solution1 {
    private List<List<Integer>> records;

    public List<Integer> grayCode(int n) {
        records = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            records.add(new ArrayList<>(1 << i));
        }
        // 1. dp初始状态，即把数字0的格雷码先加入dp中
        dp(0).add(0);
        // 2. dp递推过程，通过循环依次计算数字1, 2, 3, ..., n 的格雷码
        for (int num = 1; num <= n; num++) {
            // 数字num的格雷码的总个数2^num
            int count = 1 << num;
            for (int i = 0; i < count; i++) {
                int value;        
                if (i < count / 2) {
                    // 前半部分直接复制num-1的格雷码
                    value = dp(num - 1).get(i);
                } else {
                    // 后半部分通过在首位添加1位1得到
                    int toAdd = 1 << (num - 1);
                    value = dp(num).get(count - 1 - i) + toAdd;
                }
                dp(num).add(value);
            }
        }
        return dp(n);
    }

    /**
    * 返回num的greycode
    */
    private List<Integer> dp(int num) {
        return records.get(num);
    }
}
```

其实可以看到，上面的代码会把`[0, n]`所有数字的格雷码都存储下来，但我们其实只需要数字n的，而且n的格雷码的个数是最多的，所以我们只需要申请一个能存储下数字n的格雷码的空间就行。优化后的代码如下：

```java
class Solution2 {
    public List<Integer> grayCode(int n) {
        List<Integer> dp = new ArrayList<>(1 << n);
        dp.add(0);
        for (int num = 1; num <= n; num++) {
            int count = 1 << num;
            int toAdd = 1 << (num - 1);
            for (int i = count / 2; i < count; i++) {
                int value = dp.get(count - 1 - i) + toAdd;
                dp.add(value);
            }
        }
        return dp;
    }
}
```