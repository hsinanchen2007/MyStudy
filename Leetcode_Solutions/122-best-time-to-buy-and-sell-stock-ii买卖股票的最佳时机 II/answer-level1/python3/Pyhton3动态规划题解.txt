之前的题解已经推出贪心算法的可行性，本例给出动态规划题解代码如下：
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len( prices ) <= 1:
            return 0
        ret = [ [ 0 for i in range( len( prices ) ) ] for j in range( len( prices ) - 1 ) ]

        for i in range( len( prices ) - 1 ):
            for j in range( i + 1, len( prices ) ):
                temp = max( ret[ i - 1 ][ : i + 1 ] )
                ret[ i ][ j ] = max( temp + max( prices[ j ] - prices[ i ], 0 ), ret[ i - 1 ][ j ] )
        return ret[ -1 ][ -1 ]
```
Python3在第199个测试用例超出时间限制
核心思想如下：
令i为买入天，j为卖出天；
对某一天，获得的最大利润应该由以下两种操作之一得到：
1. 第i天买入，第j天卖出；这种情况下第j天的收益=第i天为止的收益+（第j天的价格-第i天的价格）；为防止亏损，此处与0取最大值；
2. 第i-1天以前已经买入；这种情况下第j天的收益已经在第i-1天计算完成，此处只需要拿来做比较即可；

代码时间复杂度和空间复杂度均为O(n^2),空间复杂度可优化到O(n);

本题可用动态规划的方法完成，但在代码实现层面贪心算法是更好的选择；

本题思想参考《算法图解》；

本人菜鸟，刚开始刷leetcode；
第一次写题解，写得不好请轻喷；