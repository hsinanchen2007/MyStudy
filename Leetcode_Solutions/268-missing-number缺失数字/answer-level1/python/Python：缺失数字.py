### 解题思路
0-n的和很容易求，差就是缺失的数字

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        return (n*n+n)//2-sum(nums)
```