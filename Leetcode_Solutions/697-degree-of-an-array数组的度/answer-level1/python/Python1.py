### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left={}
        right={}
        len_nums=len(nums)
        for i in range(len_nums):
            if nums[i] not in left:
                left[nums[i]]=i
        for i in range(len_nums-1,-1,-1):
            if nums[i] not in right:
                right[nums[i]]=i
        num={}
        for i in nums:
            if i not in num:
                num[i]=1
            else:
                num[i]=num[i]+1
        max=0
        maxs=[]
        for i in num:
            if num[i]>max:
                maxs=[]
                maxs.append(i)
                max=num[i]
            elif num[i]==max:
                maxs.append(i)

        ans=100000
        for i in maxs:

            if right[i]-left[i]+1<ans:
                ans=right[i]-left[i]+1

        return ans
```