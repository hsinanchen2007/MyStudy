### 解题思路
此处撰写解题思路
只有一个元素是单一的，那么所有元素的和乘以2减去原列表的和就是所求。
### 代码

```python3
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        return sum(set(nums))*2-sum(nums)
```