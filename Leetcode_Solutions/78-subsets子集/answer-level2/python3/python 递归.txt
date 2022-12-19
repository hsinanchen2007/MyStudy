### 解题思路
记录当前索引到达的位置，避免重复搜索

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        n=len(nums)
        def findSet(index,pre):
            for i in range(index,n):
                findSet(i+1,pre+[nums[i]])
            res.append(pre)      
        findSet(0,[])
        return res
```