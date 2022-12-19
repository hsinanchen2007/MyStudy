
![FireShot Capture 027 - 45. 跳跃游戏 II - 力扣（LeetCode） - leetcode-cn.com.png](https://pic.leetcode-cn.com/79999346c73097e698ffe08347c13e55d493195852e74a50bdb85d4d4381b530-FireShot%20Capture%20027%20-%2045.%20%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F%20II%20-%20%E5%8A%9B%E6%89%A3%EF%BC%88LeetCode%EF%BC%89%20-%20leetcode-cn.com.png)


### 解题思路
这个题的本质其实就是求有向图图中点对点的最短路径问题的改版：
    把每个位置都看作图的一个点，数组每个位置的值代表该点可以指向的接下来的几个点！
动态规划求解图的最短路径可以参考：[https://www.cnblogs.com/lixing-nlp/p/7688549.html](动态规划 ------最短路径问题)  
话不多说，进入题解：
1. dp代表跳跃到某位置的最少跳跃次数，初始化dp:
 dp = [MAXSIZE] * n,  dp[0] = 0
 min_i = 0(min_i代表该层最少跳跃次数的点 即该层最短路径)
2. 更新dp[i] = min(dp[min_i]+1, dp[n]) 
   min_i += 1
 若dp[-1]被更新 停止寻找，返回dp[-1]
    注：因为跳跃只能向前跳跃，所以这是一个没有’后路‘的图，上一层已经更新了的dp无需再更新，因为它的跳跃次数一定比上一层要大！该题剪枝的精髓就在此，自己想想，然后看代码！
3. 返回dp[-1]

如有疑问欢迎大家在下方评论交流！码字不易给点个赞呗Thanks♪(･ω･)ﾉ


### 代码

```python
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)
        if n == 0 or n == 1:
            return 0

        # 设置最大值
        MAXSIZE = 9999999
        #  dp代表跳跃到该位置的最少跳跃次数
        dp = [MAXSIZE] * n
        dp[0] = 0 #初始化dp[0]
        # 初始化第一个最小跳跃次数的点
        min_i = 0
        addstart =0#维护dp的起始增量
        while dp[n-1] == MAXSIZE:
            for j in range(min_i+addstart, min_i+nums[min_i]+1): #上一层已经更新了的dp无需再更新，因为它的跳跃次数一定比上一层要大 
            # 该层维护从上一层更新后的下一个点开始更新 即从min_i + nums[min_i-1]开始
                if j < n and dp[j] > dp[min_i]+1 :
                    dp[j] = dp[min_i] + 1

            if dp[-1] != MAXSIZE: #只要发现要找的最后一个点已经被维护了，停止寻找！
                break

            addstart = nums[min_i] #更新增量
            min_i += 1 



        return dp[-1]






