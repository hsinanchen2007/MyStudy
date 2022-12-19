```
def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    """
    Do not return anything, modify nums1 in-place instead.
    """
    k1 = m - 1
    k2 = n - 1

    for i in range(m + n - 1, -1, -1):
        if k2 == -1:
            break
        elif nums1[k1] < nums2[k2]:
            nums1[i] = nums2[k2]
            k2 -= 1
        else:
            nums1[i] = nums1[k1]
            k1 -= 1
    nums1[:k2 + 1] = nums2[:k2 + 1]
```
