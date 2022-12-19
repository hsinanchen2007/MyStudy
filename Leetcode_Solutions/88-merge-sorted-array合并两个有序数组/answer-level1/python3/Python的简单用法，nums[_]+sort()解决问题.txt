### 思路：
1、nums1[:]就是创建一个nums的副本，然后在副本上进行操作，就不会影响原来的nums,
2、再nums.sort() 默认升序排序，同时，此用法是在原来的nums1的基础上进行修改，不会创建新的list,而sorted(nums1)会创建一个新的list,注意这两个的用法。
### 代码：
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[:] = nums1[:m]+nums2[:n]
        nums1.sort()
```
