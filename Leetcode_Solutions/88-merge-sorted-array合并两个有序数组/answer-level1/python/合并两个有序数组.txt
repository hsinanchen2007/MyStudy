### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        l = []
        i = 0
        j = 0
        while(i < m and j < n):
            if nums1[i] <= nums2[j]:
                l.append(nums1[i])
                i = i + 1
            if nums1[i] > nums2[j]:
                l.append(nums2[j])
                j = j + 1
        if i == m and j < n:
            for k in range(j,n,1):
                l.append(nums2[k])
        if j == n and i < m:
            for k in range(i,m,1):
                l.append(nums1[k])
        for i in range(len(l)):
            nums1[i] = l[i]
```