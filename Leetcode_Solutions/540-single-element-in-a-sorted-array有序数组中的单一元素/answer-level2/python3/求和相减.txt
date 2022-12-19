### 解题思路
+ sorted list
+ 除了一个数，其他只重复两次
+ set 一遍之后*2，就是一个sorted list，所有数都是两次
+ 两个list求sum之后相减

### 代码

```python3
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        sum1 = sum(set(nums))
        sum2 = sum(nums)
        return 2*sum1-sum2
```