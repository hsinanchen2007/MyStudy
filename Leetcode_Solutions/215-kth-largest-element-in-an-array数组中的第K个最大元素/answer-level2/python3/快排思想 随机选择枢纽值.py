### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(nums, l ,r):
            rm = random.randint(l, r)
            nums[l] ,nums[rm] = nums[rm], nums[l]
            tmp = nums[l]
            i = l; j = r
            while i < j:
                while i < j and nums[j] >= tmp:
                    j -= 1
                while i < j and nums[i] <= tmp:
                    i += 1
                nums[i] ,nums[j] = nums[j], nums[i]
            nums[l] = nums[i]
            nums[i] = tmp
            return i
        def findk(nums, l, r, k):
            while l <= r:
                p = partition(nums, l, r)
                if p + 1 == k:
                    return nums[p]
                elif p + 1 > k:
                    r = p - 1
                else:
                    l = p + 1
            return False
        return findk(nums, 0, len(nums)-1, len(nums) + 1 - k)


```