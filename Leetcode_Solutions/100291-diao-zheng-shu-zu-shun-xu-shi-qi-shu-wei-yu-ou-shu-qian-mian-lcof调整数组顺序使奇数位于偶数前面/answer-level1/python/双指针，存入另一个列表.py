### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        left =0
        right = n-1
        out = [0]*n
        for i in nums:
            if i %2 ==1:
                out[left] = i
                left +=1
            else:
                out[right] =i
                right -=1
        return out

```