
官答的python版

方法一
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        nums1[:]=nums1[:m]        
        nums1.extend(nums2)
        nums1.sort()
        
```

方法二就不写了，有类似的链表题目，解法一样，而且此法也不满足o(1)的空间。

方法三
从后往前双指针

```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1=m-1
        p2=n-1
        p=len(nums1)-1
        while p1>=0 and p2>=0:
            if nums1[p1]>=nums2[p2]:
                nums1[p]=nums1[p1]
                p1-=1
            else:
                nums1[p]=nums2[p2]
                p2-=1
            p-=1
        while p1<0 and p>=0:
            nums1[p]=nums2[p2]
            p2-=1
            p-=1
```
