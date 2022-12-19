### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        num_set=list(set(nums))
        if len(num_set)<3:
            return max(num_set)
        else:
            num_set.sort()
            return num_set[-3]
```
执行用时 :
56 ms
, 在所有 python3 提交中击败了
94.91%
的用户
内存消耗 :
14.1 MB
, 在所有 python3 提交中击败了
56.46%
的用户