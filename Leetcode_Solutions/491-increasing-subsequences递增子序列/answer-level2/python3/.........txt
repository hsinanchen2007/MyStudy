* 这道题的难度在于数字会重复，先考虑没有重复的情况
    1. 加入当前数字会产生哪些新序列，只要遍历当前存在的序列并比较最后一个数字和当前数字，如果当前数字更大则加入产生新的序列
    2. 由 1 产生的新序列加上已经存在的序列以及当前数字作为一个新序列起点的情况作为新的结果
    3. 最后过滤掉长度不足 2 的序列得到最终结果
* 加入重复数字后，比如序列 $[4, 6, 7, 7]$ 遍历完前三个数字后可得到 $[[4], [4, 6], [6], [4, 7], [4, 6, 7], [6, 7], [7]]$，再加入 7 的话与前三个的组合就会和后面发生重复，所以要避免与前三个组合。利用字典保存该数字上一次出现时未组合之前结果的长度，当再次出现时只和该索引以及之后的序列进行组合，这样就避免了重复。最后去掉长度不足 2 的序列
```python
from typing import List


class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = [[nums[0]]]
        idx_map = {nums[0]: -1}
        for i in range(1, len(nums)):
            if nums[i] not in idx_map:
                idx_map[nums[i]] = len(res)
                res += [lst + [nums[i]] for lst in res if lst[-1] <= nums[i]] + [[nums[i]]]
            else:
                tmp = len(res)
                res += [res[j] + [nums[i]] for j in range(tmp) if res[j][-1] <= nums[i] and j >= idx_map[nums[i]]]
                idx_map[nums[i]] = tmp
        return [lst for lst in res if len(lst) > 1]
```