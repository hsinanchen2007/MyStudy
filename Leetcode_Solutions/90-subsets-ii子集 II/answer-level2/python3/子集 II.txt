### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        path = []
        def back(nums,result,path,index):
            k = [i for i in path]
            if k not in result:
                result.append(k)
            for i in range(index,len(nums),1):
                if i > index and nums[i] == nums[i - 1]:
                    continue
                path.append(nums[i])
                back(nums,result,path,i+1)
                path.pop()
        nums = sorted(nums)
        back(nums,result,path,0)
        return result
```