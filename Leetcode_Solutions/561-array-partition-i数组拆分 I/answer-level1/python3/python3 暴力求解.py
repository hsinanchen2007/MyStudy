### 解题思路
此处撰写解题思路
先排序，然后循环分隔，然后求解
### 代码

```python3
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        c,x=[],0
        for i in range(0,len(nums),2):
            c.append((nums[i],nums[i+1]))
        for i in c:
            x+=min(i)
        return x
            
```