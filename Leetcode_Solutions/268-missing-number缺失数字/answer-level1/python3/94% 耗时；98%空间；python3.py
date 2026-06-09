### 解题思路
此处撰写解题思路
思路非常简单，对前n项求和的结果减去对数组求和的结果，即为答案。
### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nsum = sum(range(len(nums)+1))
        return nsum - sum(nums)
```