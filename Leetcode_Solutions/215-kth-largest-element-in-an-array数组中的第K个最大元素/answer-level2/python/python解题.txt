### 解题思路
直接用python内置的列表sort()方法，会返回一个正序排列的列表，然后再从排好序的列表中取出第k大的数

### 代码

```python
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        return nums[-k]
        
        
```