
执行用时 :52 ms, 在所有 Python 提交中击败了69.03%的用户
内存消耗 :12 MB, 在所有 Python 提交中击败了100.00%的用户
### 代码

```python
class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums1=[]
        for i in range(len(nums)-1):
            if i%2==0:
                for _ in range(nums[i]):
                    nums1.append(nums[i+1])
        return nums1
```