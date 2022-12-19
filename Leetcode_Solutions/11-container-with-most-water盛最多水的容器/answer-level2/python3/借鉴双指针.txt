### 解题思路
执行用时 :24 ms, 在所有 Python 提交中击败了99.53% 的用户
内存消耗 :13.5 MB, 在所有 Python 提交中击败了5.30%的用户
不知道为啥这么快，之前提交两次都很慢，暴力法开始超时，借鉴双指针方法

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

        area = 0
        # area = min(height[i],height[j])*(abs(j - i))
        while left < right:
            area = max(area, min(height[left],height[right])*(right - left))

            if(height[left] <= height[right]):
                left = left + 1
            else:
                right = right - 1
        
        return area
```