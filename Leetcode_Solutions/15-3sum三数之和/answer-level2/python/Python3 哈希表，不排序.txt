整个思路比较简单。

满足要求的组合中，要么至多1个0，要么3个0。

至多一个0，就意味着，最大值为正，最小值为负。
只要将正数负数两两配对，那么，判断下和的相反数即可。利用 Counter 统计次数，实现很简单。

3个0的情况，判断下加上即可。

```python
import collections


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        nums_dict, res = collections.Counter(nums), []
        for left, right in ((i, j) for i in nums_dict if i < 0 for j in nums_dict if j > 0):
            mid = -left - right
            if left <= mid <= right and mid in nums_dict:
                if mid in (left, right) and nums_dict[mid] == 1:
                    continue
                res.append([left, mid, right])
        if nums_dict.get(0, 0) >= 3:
            res.append([0] * 3)
        return res
```