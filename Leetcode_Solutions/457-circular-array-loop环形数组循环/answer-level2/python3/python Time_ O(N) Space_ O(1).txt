```python
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        # if k at index is positive move forward k steps
        # conversely move backword k
        # check loop in array
        # nums.length < 5000

        # Time complexity  : O(N)
        # Space complexity : O(1)

        for i in range(len(nums)): # spacial case
            if abs(nums[i]) % len(nums) == 0:  nums[i] = 0

        def process(i, inc):
            cur = i
            flag = 1 if inc > 0 else -1
            while True:
                if flag * nums[cur] < 0 or nums[cur] == 0: break
                next = (cur + nums[cur]) % len(nums)
                nums[cur] += inc
                if abs(nums[next]) > abs(inc): return True
                cur = next 
            cur = i
            while True:
                if abs(nums[cur]) > abs(inc):
                    next = (cur + nums[cur] - inc) % len(nums)
                    nums[cur] = 0
                    cur = next
                else: break
            return False
        # Each node only visit twice, so the sum time complexity is O(2 * N)
        for i, step in enumerate(nums):
            if nums[i] == 0 : continue
            if nums[i] > 0:
                if process(i, 1000): return True
            else:
                if process(i, -1000): return True
        return False
```