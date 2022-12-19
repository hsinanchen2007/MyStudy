### 解题思路
1. 求解k个鸡蛋，扔t次， 肯定能测试出结果的最大楼层数（问题转换）
2. 带备忘录提速

### 代码

```python3
class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        # k个鸡蛋，扔t次 可以cover多少层楼（最多可以求解F=coverFloor(k,t)层楼的问题）
        memo = {}
        def coverFloor(k, t):
            if k==1: return t # 只有一个鸡蛋时，扔t次，只能从第一层开始逐层扔到t层
            if t==1 and k>0: return 1 # 只有1次机会时，只能扔在1层，cover N=1的情况
            if (k,t) in memo: return memo[(k,t)] # 备忘录
            s0 = coverFloor(k, t-1) # 扔完1次，没碎，接着向上面的楼层求解，还能cover多少层
            s1 = coverFloor(k-1, t-1) # 扔完1次，碎了，接着向下面面的楼层求解，还能cover多少层
            memo[(k,t)] = s0+s1+1 # +1表示当前扔的这一层
            return s0 + 1 + s1
        t=1
        while coverFloor(K, t)<N:
            t+=1
        return t   # 时间复杂度O(k*t)  由于memo的存在，不会重复计算

        # 面试题子问题：
        # 有 2 个蛋，用一座 100 层的楼，要使用最少次数测试出蛋几层会碎（F）。
        # 设需要t次，最优策咯如下：
        # 第一次若碎了，剩t-1次（和一个鸡蛋），则只能在0到t-1层之间求解 => 必须要满足第一次扔在第t层
        # 第一次若没碎了，只能再往下t-1层，防止碎了时，剩余一个鸡蛋和t-2次逐层遍历完之间的楼层
        # ...
        # 边界肯定是只能再往下1层
        # ==》 t次时，能cover的最大楼层数：t+(t-1)+(t-2)+...+ 2+1 >=100
        #   (t+1)*t/2 >=100求可得t=14


```

此处备忘录递归，可看作 自底向上的 动态规划
