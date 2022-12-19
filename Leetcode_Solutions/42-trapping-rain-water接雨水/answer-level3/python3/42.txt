### 解题思路
        #1.找到第一个不为0的格子，记高度为h1
        #2.向后搜索高于或者等于h1的格子
        #如果找到则执行3
        #如果没有找到则执行4
        #3.记新格子的高度为h2，之间的区域低于h1的部分可以接雨水。令h2=h1,执行2
        #4.如果h1!-0则令h1=h1-1,执行2，如果h1=0则退出程序。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:


        h1 = 0
        h2 = 0
        h1_index = -1
        h2_index = -1
        result = 0
        for i in range(len(height)):
            if height[i] != 0:
                h1_index = i
                h1 = height[i]
                break
        while h1 > 0:
            flag = True
            for i in range(h1_index+1,len(height)):
                if height[i] >= h1:
                    h2_index = i
                    h2 = height[i]
                    for i in range(h1_index+1,h2_index):
                        result += h1 - height[i]
                    h1 = h2
                    h1_index = h2_index
                    flag = False
                    break
            if flag:
                h1 -= 1
        return result
            
```