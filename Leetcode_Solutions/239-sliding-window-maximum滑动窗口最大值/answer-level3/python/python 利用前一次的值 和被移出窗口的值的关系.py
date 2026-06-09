### 解题思路
此处撰写解题思路
python 利用前一次的值 和被移出窗口的值的关系
### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return []

        res =[]
        res.append(max(nums[:k]))
        for i in range(1, len(nums)-k+1 , 1):

            if (nums[i-1] < res[i-1]):
                res.append(max(res[i-1], nums[i+k-1]))
            else:
                res.append(max(nums[i:k+i]))
        
        return res
            
```