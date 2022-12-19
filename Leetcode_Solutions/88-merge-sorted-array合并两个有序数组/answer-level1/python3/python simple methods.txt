### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        '''
        nums1[:] = sorted(nums1[:m]+nums2)
        '''
        '''
        nums1[m:m+n]=nums2
        return nums1.sort()
        '''
        '''
        p1 = m-1
        p2 = n-1
        tail = m+n-1
        while p1>=0 and p2>=0:
            if nums1[p1]<nums2[p2]:
                nums1[tail]=nums2[p2]
                p2-=1
            else:
                nums1[tail]=nums1[p1]
                p1-=1
            tail-=1
        nums1[:p2+1]=nums2[:p2+1]
        '''
        for i in range(len(nums1)-1,m-1,-1):
            del nums1[i]
        for i in range(len(nums2)):
            nums1.append(nums2[i])
        return nums1.sort()
```