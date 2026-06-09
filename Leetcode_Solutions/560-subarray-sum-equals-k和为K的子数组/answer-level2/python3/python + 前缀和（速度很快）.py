```python
from typing import List
import collections
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sumArr= [0] * (len(nums) + 1) # 求前缀和
        for i in range(len(nums)):
            sumArr[i + 1] = sumArr[i] + nums[i]
        sort_arr = [(val, i) for i, val in enumerate(sumArr)]
        sort_arr.sort(key = lambda x: (x[0], x[1]))
        cnt = 0
        sum_dic = collections.defaultdict(list)
        for val, index in sort_arr:
            sum_dic[val].append(index)
        if k == 0: # 处理0的特殊情况
            for val in sum_dic.values():
                cnt += len(val) * (len(val) - 1) // 2
            return cnt

        for val, index in sort_arr:
            for other_index in sum_dic[val - k]:
                if other_index < index: cnt += 1
        return cnt

```