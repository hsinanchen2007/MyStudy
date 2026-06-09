### 解题思路
这道题的整体思路还是回溯，属于遍历+回溯，跟LeetCode上的“括号”及“全排列”两题的思路类似。
定义一个start变量，记录开始遍历的位置。然后从start一直到nums的结尾遍历，每遍历到一个数就把它加入到当前结果tmp中。
res.append(tmp[:])这行代码一定要记得tmp[:]，如果直接加tmp的话是没办法通过的。

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(nums, tmp, start):
            res.append(tmp[:])
            for i in range(start, len(nums)):
                tmp.append(nums[i])
                backtrack(nums, tmp, i+1)
                tmp.pop()
            
        backtrack(nums, [], 0)
        return res
```