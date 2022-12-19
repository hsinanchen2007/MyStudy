```python
def merge(nums1, m, nums2, n):
    mn = m + n
    m -= 1
    n -= 1
    # 从后往前一一赋值, 将较大的值赋给num1[m + n]即可
    # 由于是写入num1, 所以只要判断n >= 0即可
    while n >= 0:
        mn -= 1
        if m >= 0 and nums1[m] > nums2[n]:
            nums1[mn] = nums1[m]
            m -= 1
        else:
            nums1[mn] = nums2[n]
            n -= 1

nums1, nums2 = [1,2,3,0,0,0], [2,5,6]
merge(nums1, 3, nums2, 3)
print(nums1)
```