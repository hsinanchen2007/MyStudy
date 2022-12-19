### 解题思路

类似插入排序 直接用nums2 往nums1里面插入
### 代码

```python
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        for i in range(n):
            if m == 0 :
                nums1[i]=nums2[i]
            for j in range(m+i,0,-1):
                # 比前面的大就把前面的往后挪
                if nums2[i] < nums1[j-1]:
                    nums1[j] = nums1[j-1]
                    nums1[j-1] = nums2[i]
                else:
                    nums1[j] = nums2[i]
                    break

    
```