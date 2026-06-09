### 解法1：合并之后再用sort函数
不符合复杂度要求
```python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1+nums2
        nums.sort()
        n = len(nums)
        if n%2 != 0:
            return float(nums[n//2])
        return (nums[n//2]+nums[n//2-1])/2
        
```
### 解法2：三指针法
  1. 设置3个指针，一个指向nums1中遍历的位置，一个指向nums2中遍历的位置，最后一个指向总的遍历的位置；
  2. 最后一个指针的跳出条件是遍历到 `(m+n)//2` 的位置；
  3. 用两个数记录总数组中相邻位置的值，用于总数是偶数的情况；
  4. ps:时间复杂度应该是 `O(m+n)` ，空间复杂度应该是常量复杂度，不知道为什么运行出来很差...

```python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        i, j, k = 0, 0, 0
        r1, r2 = 0, 0
        
        while k <= (m+n)//2:

            if j>=n or (i<m and nums1[i] < nums2[j]):
                r1, r2 = r2, nums1[i]
                i += 1
                k += 1      
            else:
                r1, r2 = r2, nums2[j]
                j += 1
                k += 1
        return float(r2) if (m+n)%2 != 0 else (r1 + r2)/2
```
