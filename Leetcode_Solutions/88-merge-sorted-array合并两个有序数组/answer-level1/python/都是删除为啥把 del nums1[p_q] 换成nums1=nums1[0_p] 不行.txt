### 解题思路
两个指针

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i=0
        j=0
        p=m+n
        q=len(nums1)+len(nums2)
        while m!=0 and n!=0:
            if nums1[i]<=nums2[j]:
                i=i+1
                m=m-1
            else:
                nums1.insert(i,nums2[j])
                j=j+1
                n=n-1
                i=i+1
        if n!=0:
            while n!=0:
                nums1[i]=nums2[j]
                i=i+1
                j=j+1
                n=n-1
            del nums1[p:q]
        else:
            del nums1[p:q]






        """
        Do not return anything, modify nums1 in-place instead.
        """
```