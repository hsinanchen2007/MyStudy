这题动态规划的思路
首先看到这题，分析之后，可以得到两个信息：
> 1. 先取的人，取到的每两个都不会相邻（后取的人这点是不一定的，后取的人这点也无所谓，与解题无关）
> 2. 要取n个（一共有3n个饼）
还有一个隐藏信息，只要两两不相邻，总有办法取到，这一点，很容易就能证明。

那么***问题的实质就是，取n个两两不相邻的饼，如何取？***
说实话，得出这个结论后，我最先想到的竟然是二分图能不能做，很遗憾，我没想出解题办法。
接下来说说dp的解题思路。

这题到这里就可以看成组合问题了，取C(3n, n)，只不过加了限制条件两两不相邻。想想在没有限制条件下，取C(3n, n)，如何操作？操作的方法有很多种，只要能覆盖所有可能性，都是可行的方案。

我采用的是这样一种方案：按索引顺序，从左往右取（这就很适合程序编码了，这里在程序中的术语就是每次取比上次索引值大的某个位置）。这种方案就能够覆盖所有的可能性。但考虑到遍历所有方案时间复杂度会很大，我们考虑使用dp优化一下

创建dp数组`dp[i][j]`：**i 表示第 i 次取值， j 表示第 i 次取索引值为 j 的位置，dp[i][j]的值存储最大索引为 j 时披萨大小总和的最大值**，所以这时的状态转移方程就应该是
```
dp[i][j] = MAX(dp[i - 1][0], ...., dp[i - 1][j - 2]) + slices[j]
```
因为有限制条件两两不相邻在，所以只到`j - 2`，不然正常情况下应该是 `j - 1`

现在，dp的状态i、j的含义有了，状态转移方程有了，就可以愉快的编程了。但是，还是有一点没有处理的，那就是饼图是首尾相接的，第0块和最后1块是不能同时取的，上面的方案明显可能覆盖首尾皆取的情况，那怎么办？可以拆分成两次dp处理，第一次对饼图的(0, 3n-1)个进行一次dp，第二次对饼图的(1, 3n)个进行第二次dp，最后取两次dp的最大值，就是最终的结果了。


编码如下，代码里有稍许改变，由于每次都只用上次取值的dp，所以上面说的dp[i][j]就没做二维数组了，只作了一维的dp数组，循环使用：
```java
class Solution {
    public int maxSizeSlices(int[] slices) {
        int[] dp1 = new int[slices.length - 1];
        int[] dp2 = new int[slices.length - 1];
        for (int i = 0; i < dp1.length; i++) {
            dp1[i] = slices[i];
            dp2[i] = slices[i + 1];
        }

        int n = slices.length / 3;
        for (int i = 1; i < n; i++) {
            int[] dpp = new int[slices.length - 1];
            dpp[0] = slices[0];
            dpp[1] = slices[1];
            int max = dpp[0];
            for (int j = 2; j < dpp.length; j++) {
                dpp[j] = max + slices[j];
                max = Math.max(max, dp1[j - 1]);
            }
            dp1 = dpp;

            dpp = new int[slices.length - 1];
            dpp[0] = slices[1];
            dpp[1] = slices[2];
            max = dpp[0];
            for (int j = 2; j < dpp.length; j++) {
                dpp[j] = max + slices[j + 1];
                max = Math.max(max, dp2[j - 1]);
            }
            dp2 = dpp;
        }

        int max = Math.max(dp1[0], dp2[0]);
        for (int i = 0; i < dp1.length; i++) {
            max = Math.max(max, dp1[i]);
            max = Math.max(max, dp2[i]);
        }

        return max;
    }

}
```