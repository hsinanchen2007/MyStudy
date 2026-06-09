### 解题思路
虽然自己的做法就是快排，但就是一些边界没弄清晰，搞得心烦意乱！

### 代码

```python
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if len(nums) <= 0 or k > len(nums) or k <= 0:
            return None
        return self.findKth(nums, 0, len(nums)-1, len(nums)-k)
    
    def findKth(self, nums, left, right, k):
        if left == right:
            return nums[left]
        idx = self.partition(nums, left, right)
        # print(nums, idx, k)
        if idx == k:
            return nums[idx]
        elif idx > k:
            return self.findKth(nums, left, idx-1, k)
        else:
            return self.findKth(nums, idx+1, right, k)


    def partition(self, nums, left, right):
        idx = random.choice(list(range(left, right+1)))
        privot = nums[idx]
        nums[right], nums[idx] = nums[idx], nums[right]
        idx = left
        for i in range(left, right):
            if nums[i] < privot:
                nums[idx], nums[i] = nums[i], nums[idx]
                idx += 1
        nums[idx], nums[right] = nums[right], nums[idx]
        return idx
```