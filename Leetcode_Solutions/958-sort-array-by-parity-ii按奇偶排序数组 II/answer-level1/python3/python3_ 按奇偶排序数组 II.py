```python
def sortArrayByParityII(A):
    nums1 = list(filter(lambda a: a % 2 == 0, A))
    nums2 = list(filter(lambda a: a % 2 == 1, A))
    A[::2], A[1::2] = nums1, nums2
    return A

print(sortArrayByParityII([4,2,5,7]))
```