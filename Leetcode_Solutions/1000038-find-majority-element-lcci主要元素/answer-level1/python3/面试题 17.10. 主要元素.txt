### 解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dico = collections.Counter(nums)
        for i, j in dico.items():
            if j > len(nums)//2: return i
        return -1
```