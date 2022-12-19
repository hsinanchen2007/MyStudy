一开始我的做法是用一个二维数组来做dp，但后来发现，其实每次只需要保存上一步dp的两个值即可，于是对dp方法又做了改进，首先说一下用二维数组做dp的方法：

dp数组有两行：

- 第一行表示走当前阶梯，如果走了当前阶梯，则第n-1个阶梯可走可不走，取走与不走的最小值加上当前第n步的花费，即为走当前步的最小值，则最低花费为
$$dp[0][n] = min(dp[0][n-1],dp[1][n-1]) + cost[n]$$


- 第二行表示不走当前阶梯：如果不走当前阶梯，则第n-1个阶梯是必须走的，否则无法继续走下去，最低花费的dp公式为：
$$dp[1][n] = dp[0][n-1]$$


最终比较dp数组中每一维的最后一个元素的大小，较小的即为最终花费，因为最后一步其实可走可不走，最终cost为：

$$min\_cost = min(dp[0][len(cost)], dp[1][cost])$$


```python
import numpy as np

class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
       
        length = len(cost)
        dp = np.zeros((2, length))
        
        
        dp[0][1] = cost[1]
        dp[1][1] = cost[0]
        
        for n in range(2, length):
            
            dp[0][n] = min(dp[0][n-1], dp[1][n-1]) + cost[n]
            dp[1][n] = dp[0][n-1]
            
        return int(min(dp[0][length-1], dp[1][length-1]))
        
        

```

而其实我们观察上面的dp过程，可以发现，当前阶梯的最低花费值其实是可以由两个值确定：经过前一个阶梯的最低花费和不经过前一个阶梯的最低花费：

- 走过当前阶梯的最低花费由走过上一个阶梯的最低花费和不走过上一个阶梯的最低花费的最小值加上当前阶梯的花费得到，dp公式为:
$$tmp_have_cur = min(have_cur, have_no_cur) + cost[n]$$
- 不走过当前阶梯的最低花费由走过前一个阶梯的最低花费决定，dp公式为：
$$tmp_have_no_cur = have_cur$$

初始化是从是否经过第二个阶梯开始的，因为题目给了cost数组必定会大于等于2，所以我们初始化直接从是否经过第二个台阶即可。

具体代码如下：
```python

import numpy as np

class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
      
        have_cur = cost[1]
        have_no_cur = cost[0]
        cost_len = len(cost)
        
        for n in range(2, cost_len):
            
            tmp_have_cur = min(have_cur, have_no_cur) + cost[n]
            tmp_have_no_cur = have_cur
            
            have_cur = tmp_have_cur
            have_no_cur = tmp_have_no_cur
            
        return min(have_cur, have_no_cur)
        

    
solution = Solution()
print(solution.minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))




```