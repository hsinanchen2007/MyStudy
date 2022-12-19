### 主要思想

哈希表记录数字出现次数 + 分正负 + 减法，判断差是否出现

```python
class Solution(object):
    def threeSum(self, nums):
        res, negs, poses = [], [], []
        num_times = {}

        for num in nums:
            num_times[num] = num_times.get(num, 0) + 1

        for num in num_times:
            if num < 0:
                negs.append(num)
            else:
                poses.append(num)

        if num_times.get(0, 0) >= 3:
            res.append([0, 0, 0])

        for neg in negs:
            for pos in poses:
                diff = 0 - neg - pos
                if diff in num_times:
                    if diff in (neg, pos) and num_times.get(diff) >= 2:
                        res.append([neg, diff, pos])
                    elif diff > pos or diff < neg:
                        res.append([neg, diff, pos])
        return res

```