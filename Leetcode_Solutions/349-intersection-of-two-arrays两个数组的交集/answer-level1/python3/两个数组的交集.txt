python set 集合的灵活运用
```python

def intersection(nums1, nums2):
        return list(set(nums1) & set(nums2))
        # 或者是
        return list(set(nums1).intersection(nums2))   # 注意函数不要同名
```