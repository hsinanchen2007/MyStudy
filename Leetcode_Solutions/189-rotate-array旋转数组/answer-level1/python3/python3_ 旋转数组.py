```python
def rotate(nums, k):
    # 对k进行求余
    k %= len(nums)
    nums[:] = nums[-k:] + nums[0:-k]
    
nums1, nums2 = [1,2,3,4,5,6,7], [1,2,3,4,5,6,7]
rotate(nums1, 3)
rotate(nums2, 23)
print(nums1, nums2)
```