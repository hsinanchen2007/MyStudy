## 思路

分析题意可知，

因为把长度分别为`X`和`Y`的两根棒材连接在一起，需要支付`X + Y`的费用，

所以要想让总费用最低，那么初始长度越长的棒材的合成次数就应该越少越好，

每次合并的，最好能是当前最短的棒材和当前第二短的棒材，

这样就能使得本次合并的费用最少。

因此，本题要做的就是在每次合并时，找到长度最小的和长度第二小的棒材，

找最小值可以用优先级队列实现。

## 代码实现

```Python
class Solution(object):
    def connectSticks(self, sticks):
        """
        :type sticks: List[int]
        :rtype: int
        """
        from heapq import * 
        heapify(sticks) # 建优先级队列
        res = 0
        while len(sticks) > 1:
            s1 = heappop(sticks) #找到最短的棒材
            s2 = heappop(sticks) #找到第二短的棒材
            res += s1 + s2 #把最短的两根棒子连接在一起
            heappush(sticks, s1 + s2) #把连接好的棒材放进队
        return res 


```

## 复杂度分析

时间复杂度：$O(nlogn)$

空间复杂度：$O(n)$