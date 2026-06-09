### 解题思路
基本思想就是不断比较头数字的大小进行排序。
但是不太理解，为啥最后的赋值不能nums1 = result

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
        result = []
        a, b = 0, 0
        while a < m and b < n:
            if nums1[a] < nums2[b]:
                result.append(nums1[a])
                a += 1
            else:
                result.append(nums2[b])
                b += 1
        if a < m:
            result += nums1[a:m]
        if b < n:
            result += nums2[b:]
        nums1[:] = result[:]
```