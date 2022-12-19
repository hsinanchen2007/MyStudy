### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(p, r):
            i = p
            h = random.randint(p, r)
            nums[r], nums[h] = nums[h], nums[r]
            for j in range(p, r):
                if nums[j] > nums[r]:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[r], nums[i] = nums[i], nums[r]
            return i

        def kth(p, r, s):
            if p >= r: return
            q = partition(p, r)
            if q == s: return
            elif q > s: kth(p, q - 1, s)
            else: kth(q + 1, r, s)
        
        n = len(nums)
        kth(0, n - 1, k - 1)
        return nums[k - 1]
```