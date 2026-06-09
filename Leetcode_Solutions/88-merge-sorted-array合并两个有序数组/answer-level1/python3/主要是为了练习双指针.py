### 解题思路
其实Python可以有很简洁的写法，另外这个题有点迷惑的是应该是len(nums1) = m + n， 一开始按照len(nums1)可能大于m + n，发现提交总是解答错误。

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j = m - 1,  n - 1
        while i >= 0 and j >= 0:
            if nums1[i] <= nums2[j]:
                nums1[i + j + 1] = nums2[j]
                j -= 1
            else:
                nums1[i + j + 1] = nums1[i]
                i -= 1
        if j >= 0:
            nums1[:j + 1] = nums2[:j + 1]
```