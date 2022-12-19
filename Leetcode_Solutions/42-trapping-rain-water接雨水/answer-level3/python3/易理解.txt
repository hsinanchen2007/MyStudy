基本思路是求出接满雨水后的数组，减去原来的数组就是雨水。
首先求出数组最高点和索引位置
从左到最高点遍历，如果当前位置比下一位置高，就把当前位置高度赋值给下一位置
从右到最高点遍历，如果当前位置比下一位置高，就把当前位置高度赋值给下一位置
得出新数组即为接满雨水的数组，求和相减即可
```
class Solution:
    def trap(self, height: List[int]) -> int:
        s=sum(height)
        max_height=0                  
        max_index=0
        for i in range(len(height)):
            if height[i]>=max_height:
                max_height=height[i]
                max_index=i
        for j in range(max_index):
            if height[j]>height[j+1]:
                height[j+1]=height[j]
        for n in range(len(height)-1,max_index,-1):
            if height[n]>height[n-1]:
                height[n-1]=height[n]
        return sum(height)-s
```
