```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        self._nums, self._target = nums, target
        self._start, self._end = len(nums), -1

        self._bisearch(0, len(nums) - 1)
        
        if self._start == len(nums) and self._end == -1:
            return 0
        else:
            return self._end - self._start + 1

    def _bisearch(self, left, right):
        if left > right:
            return 

        mid = left + (right - left) // 2
        if self._nums[mid] == self._target:
            self._start = min(self._start, mid)
            self._end = max(self._end, mid)

        self._bisearch(mid+1, right)
        self._bisearch(left, mid - 1)
```