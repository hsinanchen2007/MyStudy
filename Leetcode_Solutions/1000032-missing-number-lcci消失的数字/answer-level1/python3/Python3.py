### 解题思路
用index记录位置

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        index = [""]*(len(nums)+1)
        for i in nums:
            index[i] = i
        for j in index:
            if j == "":
                return index.index(j)
```