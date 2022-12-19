

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if n * k == 0:
            return []
        if k == 1:
            return nums
        left = [0] * n
        right = [0] * n
        left[0] = nums[0]
        right[n-1] = nums[n-1]

        for i in range(1,n):
            if i % k == 0:
                left[i] = nums[i]
            else:
                left[i] = max(nums[i],left[i-1])
            j = n - i  - 1
            if (j + 1) % k == 0:
                right[j] = nums[j]
            else:
                right[j] = max(nums[j],right[j + 1])
        print(left)
        print(right)
        res = []
        for i in range(n - k + 1):
            res.append(max(left[i + k - 1],right[i]))
        return res

```