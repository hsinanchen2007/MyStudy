```python
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        # Find the longest continuous string which gap smaller than zero_cnt
        zero_cnt, one_cnt, sum_one = 0, 0, sum(data)
        j, res = 0, 0
        for i in range(len(data)):
            if data[i] == 0: zero_cnt += 1
            else: one_cnt += 1
            while zero_cnt  > sum_one - one_cnt:
                if data[j] == 0: zero_cnt -= 1
                else: one_cnt -= 1
                j += 1
            res = max(res, one_cnt)
        return sum_one - res
```