![TIM截图20191205200731.png](https://pic.leetcode-cn.com/8ce939741230cc310f164d93477a103526037786bfb6be48d8f7d278373655c7-TIM%E6%88%AA%E5%9B%BE20191205200731.png)

### 解题思路
第一步： 问题转化
        要使得两个子集元素和相等，即为从数组中挑出部分元素组成集合A，使得sumA = SUM - sumA；
        也就是sumA = SUM / 2；这便是一个经典的0 - 1背包问题。
        假如SUM为奇数，直接返回false。
第二步： 动态规划解决0 - 1背包问题
        建立dp数组，长度target = sum + 1;
        dp[i]表示的为nums数组此时能否组成和为i的状态，dp[0] = 1;
        我们让num遍历数组nums，对于每一个num，建立内层循环i = target,当i >= num的时候，更新dp[i]
        假如dp[i - num]为true，则表示在num之前的数组可以找出和为i - num的集合，那么再加入了num之            后，数组也能找出和为i的集合，于是dp[i]更新为true。
        最后，返回dp[target]即可。



### 代码
![TIM图片20191205203444.jpg](https://pic.leetcode-cn.com/2e8d07557122f1a40e21e25799f88b4fa4271b7037b0232e3532a627805318a0-TIM%E5%9B%BE%E7%89%8720191205203444.jpg)

```java
class Solution {
    public boolean canPartition(int[] nums) {
        //转化为经典的01背包问题
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        //建立dp数组，dp[i]表示能否找到和为i的数组元素集合
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                if (dp[i - num] == true)
                    dp[i] = true;
            }
        }
            return dp[target];
    }
}
```