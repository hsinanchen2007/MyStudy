### 解题思路
思路：对每一个格子，找它后面跟它一样高或者比它高的格子，如果这样的格子存在，就计算他们之间能乘多少水
如果不存在，那么就找它后面最高的格子，计算他们之间能乘多少水
然后将起点更新到上一步找到的那个格子，往后面搜寻

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        #思路：对每一块格子，都寻找是否有能接水的格子来配对
        #先找到第一个非0的格子
        if height == []:
            return 0
        start = -1
        for i in range(len(height)):
            if height[i] != 0:
                start = i
                break
        if start == -1:
            return 0
        res = 0
        while start < len(height)-1:
            #ok,优先找后面比自己高的格子，如果莫得就找比自己低的中最高的
            min_max = 0 
            min_max_index = -1
            end = -1
            for i in range(start+1,len(height)):
                if height[i] >= height[start]:
                    #找到了，可以装水咯
                    end = i
                    break
                else:
                    if height[i] > min_max:
                        min_max = height[i]
                        min_max_index = i
            if end == min_max_index == -1:
                #说明后面无法接水了
                return res 
            if end != -1:
                #说明有比它高的能接水的
                water = (end - start -1)*height[start]-(sum(height[start+1:end]))
                res += water
                start = end
            if end == -1 and min_max_index != -1:
                #说明它比较高，后面没有比它更高的了
                water = (min_max_index - start -1) * height[min_max_index] - (sum(height[start+1:min_max_index]))
                res += water
                start = min_max_index
        return res
```