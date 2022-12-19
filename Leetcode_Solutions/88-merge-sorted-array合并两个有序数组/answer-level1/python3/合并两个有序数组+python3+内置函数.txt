### 解法1：内置函数sort
```python []
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        for i in range(m,m+n):
            nums1[i] = nums2[i-m]
        nums1.sort()
```

### 解法2：从后往前归并
```python []
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i, j, k = m-1, n-1, m+n-1
        while i>=0 and j>=0:
            if nums1[i]>nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
                k -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
                k -= 1
        for i in range(0,j+1):
            nums1[i] = nums2[i]
```
