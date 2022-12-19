### 解题思路
数学方法求 0 ~ n+1 的值，减去nums的和
- 高斯函数 n*(n+1)/2
- 构造列表，利用sum函数

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return int(len(nums)*(len(nums)+1)/2 - sum(nums))
```

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return sum([i for i in range(len(nums)+1)]) - sum(nums)
```
