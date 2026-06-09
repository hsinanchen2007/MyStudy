### 解题思路
首先复制nums1的有效部分出来，当然这一步要耗费不少内存，也许有更好的方法。
然后双指针依次比较，写入nums1就好了

当然还有一个方法就是直接把nums2写入nums1的后半部分，然后直接对nums1 快排就好了

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        temp = nums1[:m]
        p1 = 0
        p2 = 0
        p = 0
        while p1<m and p2<n:
            if temp[p1]>nums2[p2]:
                nums1[p]=nums2[p2]
                p2+=1
            else:
                nums1[p]=temp[p1]
                p1+=1
            p+=1
        while p1<m:
            nums1[p]=temp[p1]
            p1+=1
            p+=1
        while p2<n:
            nums1[p]=nums2[p2]
            p2+=1
            p+=1

```