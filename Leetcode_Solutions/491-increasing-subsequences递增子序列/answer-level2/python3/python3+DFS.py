### 解题思路
没找到太好的去重方法，就用了set去重

### 代码

```python3
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 2:
            return []
        ans = set()
        def helper(nums,i,tmp):
            if len(tmp) >= 2:
                ans.add(tuple(tmp))
                tmp = tmp[:]
            for j in range(i+1,len(nums)):
                if nums[j] >= tmp[-1]:
                    if tuple(tmp+[nums[j]]) not in ans:
                        helper(nums,j,tmp+[nums[j]])
        for i in range(len(nums)):
            helper(nums,i,[nums[i]])
        return [list(a) for a in ans]
```