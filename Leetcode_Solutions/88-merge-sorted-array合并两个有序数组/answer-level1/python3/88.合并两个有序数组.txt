### 解题思路
反向遍历，从最大的开始比较，从nums1的后面依次填入。

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = m+n-1
        m,n = m-1,n-1
        while n>=0 and m>=0:
            if nums1[m] > nums2[n]:
                nums1[i] = nums1[m]
                i -= 1
                m -= 1
            elif nums1[m] < nums2[n]:
                nums1[i] = nums2[n]
                i -= 1
                n -= 1
            else:
                nums1[i],nums1[i-1] = nums1[m],nums2[n]
                i -= 2
                n -= 1
                m -= 1
        while n >= 0:
            nums1[i] = nums2[n]
            i -= 1
            n -= 1
```