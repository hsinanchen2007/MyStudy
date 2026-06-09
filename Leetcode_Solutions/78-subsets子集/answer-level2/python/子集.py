### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        path = []
        def back(nums,result,path,index):
            result.append([i for i in path])
            for i in range(index,len(nums),1):
                path.append(nums[i])
                back(nums,result,path,i+1)
                path.pop()
        back(nums,result,path,0)
        return result
            
```