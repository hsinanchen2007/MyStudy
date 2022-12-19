### 解题思路
首先对nums进行排序，方便回溯的过程中遇到连续相等的值方便剪枝
这道题目与全排列很相似，只不过是在计算全排列的过程中在去重的前提下，把每一步的结果都存下来

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def backtrack(L, temp):
            res.append(temp)
            for i in range(len(L)):
                if i > 0 and L[i] == L[i-1]:
                    continue
                backtrack(L[i+1:], temp+[L[i]])
        nums.sort()
        res = []
        backtrack(nums, [])
        return res
```