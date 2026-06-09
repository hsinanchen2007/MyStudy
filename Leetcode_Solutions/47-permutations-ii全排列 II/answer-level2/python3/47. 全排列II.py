### 解题思路
与上一题同样地思路，回溯模板准备好，不过考虑到重复情况，还需要剪枝处理。重复的部分，利用滑动窗口技巧过滤掉。

### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrack(nums,combination):
            if not nums:
                res.append(combination)
                return
            else:
                i=0
                while i<len(nums):
                    while i<len(nums)-1 and nums[i]==nums[i+1]:
                        i+=1
                    backtrack(nums[:i]+nums[i+1:],combination+[nums[i]])
                    i+=1
        nums.sort()
        backtrack(nums,[])
        return res
```