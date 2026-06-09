```python
    def majorityElement(self, nums: List[int]) -> List[int]:
        # 摩尔投票法
        m = n = None
        mcount = ncount = 0
        for num in nums:
            if num == m:
                mcount += 1
            elif num == n:
                ncount += 1
            elif not mcount:
                m, mcount = num, 1
            elif not ncount:
                n, ncount = num, 1
            else:
                mcount -= 1
                ncount -= 1
        mcount = ncount = 0
        for num in nums:
            if num == m:
                mcount += 1
            elif num == n:
                ncount += 1
        N = len(nums)
        return [i for i, c in zip((m, n), (mcount, ncount)) if c > N//3]
```