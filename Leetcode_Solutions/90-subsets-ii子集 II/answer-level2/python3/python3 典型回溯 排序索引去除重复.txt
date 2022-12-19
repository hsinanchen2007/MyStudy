### 解题思路
此处撰写解题思路
和之前的题目类似，排序索引去除重复，但是不知道为什么时间这么慢。。。

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = [[],nums]
        nums.sort()

        def helper(nums,index,k,res):
            if k==0:
                ans.append(res[:])
            pre = float('inf')
            for i in range(index,len(nums)):
                if nums[i]!=pre:
                    res.append(nums[i])
                    helper(nums,i+1,k-1,res)
                    res.pop()
                pre = nums[i]
        
        for i in range(1,len(nums)):
            res = []
            helper(nums,0,i,res)
        return ans
```