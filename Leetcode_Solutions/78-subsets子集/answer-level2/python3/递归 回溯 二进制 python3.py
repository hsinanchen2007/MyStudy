### 解题思路
递归 回溯 二进制

### 代码

```python3
# https://leetcode-cn.com/problems/subsets/
class Solution_recursion:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for num in nums:
            res += [cur + [num] for cur in res]
        return res


class Solution_backtrack:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        n = len(nums)

        def backtrack(tgt_len, cur_num=0, res_tmp=None):
            if res_tmp is None:
                res_tmp = []
            if len(res_tmp) == tgt_len:
                res.append(res_tmp)
                return
            for i in range(cur_num, n):
                res_tmp.append(nums[i])
                backtrack(tgt_len, i + 1, res_tmp)
                res_tmp.pop()

        for tgt_len in range(1, n + 1):
            backtrack(tgt_len)
        return res

class Solution_bin:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        for i in range(2 ** n):
            index = 0
            res_tmp = []
            ii = i
            while index < n:
                if ii % 2:
                    res_tmp.append(nums[index])
                index += 1
                ii >>= 1
            res.append(res_tmp)
        return res
    
```