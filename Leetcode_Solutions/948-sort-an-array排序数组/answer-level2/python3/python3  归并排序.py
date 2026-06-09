### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def merge(nums, p, mid, r):
            temp = []
            left, right = p, mid + 1
            
            while left <= mid and right <= r:
                if nums[left] <= nums[right]: 
                    temp += [nums[left]]
                    left += 1
                else:
                    temp += [nums[right]]
                    right += 1
            if left <= mid:temp += nums[left:mid+1]
            elif right <= r: temp += nums[right:r+1]
            nums[p:r+1] = temp

        def sort(nums, p, r):
            if p >= r: return 
            mid = (p + r)//2
            sort(nums, p, mid)
            sort(nums, mid + 1, r)
            merge(nums, p, mid, r)
        
        n = len(nums)
        sort(nums, 0, n-1)
        return nums


```