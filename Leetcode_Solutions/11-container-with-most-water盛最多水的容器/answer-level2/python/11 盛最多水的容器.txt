### 解题思路
所有消去的状态的面积都 < S(i, j)。通俗的讲，我们每次向内移动短板，所有的消去状态都不会导致丢失面积最大值 。


### 代码

```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        i, j, maxval = 0, len(height)-1, 0 

        while i < j:
            if height[i] < height[j]:
                maxval = max(maxval, height[i]*(j-i))
                i += 1
            else:
                maxval = max(maxval, height[j]*(j-i))
                j -= 1

        return maxval
```