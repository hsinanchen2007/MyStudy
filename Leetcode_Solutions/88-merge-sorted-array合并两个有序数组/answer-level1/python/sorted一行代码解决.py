### 解题思路
sort只是对对象本身进行排序，没有返回值，要注意，sorted()会返回一个副本，对象本身不会发生改变

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[:m+n] = sorted(nums1[:m]+nums2[:n])


'''
        i1 = m-1
        i2 = n-1
        k = m+n-1
        if n == 0:
            pass
        elif m == 0:
            nums1[:n] = nums2
        while i1 > -1 and i2 > -1:
            if nums1[i1] < nums2[i2]:
                nums1[k] = nums2[i2]
                i2 -= 1
                k -=1
            else:
                nums1[k] = nums1[i1]
                i1 -= 1
                k -= 1
        if i1 > -1:
            pass
        if  i2 > -1:
            nums1[:i2+1] = nums2[:i2+1]
'''


```