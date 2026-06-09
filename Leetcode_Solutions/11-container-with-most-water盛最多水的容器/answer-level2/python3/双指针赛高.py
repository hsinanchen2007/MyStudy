### 解题思路
双指针赛高哦
想到的第一个想法就是直接暴力穷举
复杂度O（n^2）直接超时
```pythin
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        water = 0
        for i in range(length):
            for j in range(i+1,length):
                curr = min(height[i],height[j])*(j-i)
                water = max(curr,water)
        return(water)

```
双指针直接降到O（n）
其实就是利用先验减小求解域 思路很重要


### 代码

```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        left = 0
        right = length - 1
        res = 0
        while right > left:
            if height[left] < height[right]:
                res = max(res, height[left] * (right-left))
                left += 1
            else:
                res = max(res, height[right] * (right-left))
                right -= 1
        return res


```