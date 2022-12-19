### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def minArray(self, numbers):
        """
        :type numbers: List[int]
        :rtype: int
        """
        right=len(numbers)-1
        left = 0
        while (left<right-1):
            mid = (left+right)/2
            if numbers[mid]>numbers[right]:
                left = mid 
            elif numbers[mid] <numbers[right]:
                right = mid
            else:
                right = right-1
        if numbers[left]>numbers[right]:
            return numbers[right]
        else:
            return numbers[left]
```