```python
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        # over n / 3
        # the most cnt is 2
        def check_cnt(p, k):
            cnt = 0
            for num in nums:
                if num == p: cnt += 1
            return cnt > k

        p1, p2 = None, None
        cnt1, cnt2 = 0, 0
        for num in nums:
            if num == p1:
                cnt1 += 1
            elif num == p2:
                cnt2 += 1
            elif cnt1 == 0:
                p1 = num
                cnt1 += 1
            elif cnt2 == 0:
                p2 = num
                cnt2 += 1
            else:
                cnt1 -= 1
                cnt2 -= 1
        res = []
        if check_cnt(p1, len(nums) // 3):
            res.append(p1)
        if check_cnt(p2, len(nums) // 3):
            res.append(p2)
        return res
```