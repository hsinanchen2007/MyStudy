### 解题思路
此处撰写解题思路

### 代码

```python3
class cmpSmaller(str):
    def __lt__(self,y):
        return self+y<y+self
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        nums = sorted(map(str,nums),key=cmpSmaller)
        return ''.join(nums)
```