### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        a=list(set(nums))
        a.sort(reverse=True)
        if len(a)<3:
            return a[0]
        else:
            return a[2]
```