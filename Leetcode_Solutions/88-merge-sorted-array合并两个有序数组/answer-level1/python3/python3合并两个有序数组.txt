### 解题思路
双指针一次遍历比较

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i=0
        j=0
        while j<n:
            if i<m and nums2[j]<nums1[i]:
                k=m-1
                while k>=i:
                    nums1[k+1]=nums1[k]
                    k-=1
                nums1[i]=nums2[j]
                m+=1
                j+=1
            elif i>=m:
                nums1[i]=nums2[j]
                j+=1
            i+=1
```