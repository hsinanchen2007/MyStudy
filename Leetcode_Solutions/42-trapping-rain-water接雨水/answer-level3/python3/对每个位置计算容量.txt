这个问题最容易实现的方法就是在每个位置计算该位置的容量，不需要太多行代码。
我们都知道水桶的容量取决于周围的短板，而对于每个位置，水桶由左侧板和右侧板构成，两侧都有很多块板，每侧最长的那个组成该侧的木板，左侧板和右侧板中最短的决定容量
1、计算左侧最长板，右侧最长板
2、取最小值-当前高度=该位置容量
```
class Solution:
    def trap(self, height: List[int]) -> int:
        #maxh = max(height)
        count = 0
        for i in range(1,len(height)-1):
            left = max(height[:i])
            right = max(height[i+1:])
            if height[i] < left and height[i] < right:
                count+= min(left,right)-height[i]
        return count
```

