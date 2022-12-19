```python
from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        nums.sort()
        def back_tracking(i: int, tmp: List[int]) -> None:
            if i == len(nums): return
            for j in range(i, len(nums)):
                if j > i and nums[j] == nums[j - 1]: continue
                res.append(tmp+[nums[j]])
                back_tracking(j+1, tmp+[nums[j]])
        back_tracking(0, [])
        return res

    def subsetsWithDup1(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        nums.sort()
        pre_len = len(res)
        for i in range(len(nums)):
            tmp = []
            for j in range(len(res)-1, -1, -1):
                if i >= 1 and nums[i-1] == nums[i]:
                    if pre_len > 0:
                        tmp.append(res[j]+[nums[i]])
                        pre_len -= 1
                else:
                    tmp.append(res[j]+[nums[i]])
            pre = len(res)
            res.extend(tmp)
            pre_len = len(res) - pre
        return res
```