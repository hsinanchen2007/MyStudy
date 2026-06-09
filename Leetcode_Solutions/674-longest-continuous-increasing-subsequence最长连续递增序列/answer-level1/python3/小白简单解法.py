### 解题思路
1.空列表返回0
2.逐项和后项对比。若小则c+1，并和max_c比较，取大；若大则将c清为1
3.返回max_c
执行用时 :88 ms, 在所有 Python 提交中击败了14.42%的用户
内存消耗 :12.7 MB, 在所有 Python 提交中击败了84.38%的用户
### 代码

```python
class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        c=1
        max_c=1
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                c+=1
                if c>max_c:
                    max_c=c
            else:
                c=1
        return max_c

```