### 解题思路
执行用时 :
276 ms
, 在所有 Python3 提交中击败了
6.85%
的用户
内存消耗 :
13.8 MB
, 在所有 Python3 提交中击败了
99.25%
的用户

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i=0
        while i<len(nums):
            if nums[i]==0:
                nums.remove(0)
                nums.append(0)
            i+=1







```