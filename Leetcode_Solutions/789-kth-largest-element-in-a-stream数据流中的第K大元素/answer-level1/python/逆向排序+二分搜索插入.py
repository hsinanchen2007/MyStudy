### 解题思路
时间复杂度：O（log（n））
空间复杂度：O（1）

### 代码

```python3
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = nums
        self.k = k
        if self.k < 0:
            self.k = 0

        self.nums = sorted(nums)[::-1]

    def add(self, val: int) -> int:
        if not self.nums:
            self.nums.append(val)
            if self.k < 2:
                return self.nums[self.k - 1]
        low = 0
        high = len(self.nums) - 1
        while low < high:
            mid = (low + high) // 2
            if self.nums[mid] < val:
                high = mid - 1
            elif self.nums[mid] > val:
                low = mid + 1
            else:
                self.nums.insert(mid, val)
                break
        if low >= high:
            if val > self.nums[low]:
                self.nums.insert(low, val)
            else:
                self.nums.insert(low+1, val)
        if len(self.nums) >= self.k:
            return self.nums[self.k-1]
        return -1
```