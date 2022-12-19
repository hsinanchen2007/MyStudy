```
def firstMissingPositive(self, nums: List[int]) -> int:
        first_missing = -1
        max_len = len(nums)
        if max_len == 0:
            return 1
        left = [False] * max_len
        for n in nums:
            if 0 < n <= max_len:
                res = n % max_len
                left[res] = True
        left.append(left[0])
        for i in range(1, max_len+1):
            if not left[i]:
                first_missing = i
                break
        if all(left):
            first_missing = max_len + 1
        return first_missing
```
