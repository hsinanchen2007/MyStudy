### 解题思路
双指针+从后往前遍历，直接在nums1上操作
时间复杂度：O(m+n)
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i,j=m-1,n-1
        p=m+n-1
        while i>=0 and j>=0:
            if nums2[j]>=nums1[i]:
                nums1[p]=nums2[j]
                j-=1
            else:
                nums1[p]=nums1[i]
                i-=1
            p-=1
        if j>=0:
            nums1[:j+1]=nums2[:j+1]
```