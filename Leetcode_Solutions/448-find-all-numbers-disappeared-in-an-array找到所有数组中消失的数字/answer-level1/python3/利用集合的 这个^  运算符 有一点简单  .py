### 解题思路
执行用时 :380 ms, 在所有 Python3 提交中击败了94.84%的用户
内存消耗 :29.7 MB, 在所有 Python3 提交中击败了5.02%的用户

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        compare=set(range(1,len(nums)+1))
        a=set(nums)
        return  compare ^ a

```