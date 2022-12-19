### 解题思路
方法一：
这个时间复杂度，必然是分治思想的产物
经典二分法

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        if n == 0:
            raise ValueError
        imin, imax, half_len = 0, m, (m + n + 1) / 2
        while imin <= imax:
            i = int((imin + imax) / 2)
            j = int(half_len - i)
            if i < m and nums2[j-1] > nums1[i]:
                imin = i + 1
            elif i > 0 and nums1[i-1] >nums2[j]:
                imax = i - 1
            else:
                if i == 0: max_of_left = nums2[j-1]
                elif j == 0: max_of_left = nums1[i-1]
                else: max_of_left = max(nums1[i-1], nums2[j-1])
                if (m + n) % 2 == 1:
                    return max_of_left
                if i == m: min_of_right = nums2[j]
                elif j == n: min_of_right = nums1[i]
                else: min_of_right = min(nums1[i], nums2[j])
                return (max_of_left + min_of_right) / 2.0

```

###解题思路
方法二：
鸡贼套路
利用Python函数完成

###代码
```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        length=len(nums1)
        if length%2==1:
            return nums1[length//2]
        else:
            return (nums1[length//2]+nums1[length//2-1])/2
            #利用//强行整数化
```

刚好看到评论，没绑定手机，就这里回复一下：
python的list.sort使用的是timesort这个机制，本质上是归并和插排的结合体，时间复杂度为nlogn,最差为nlogn,最优为n,在这里的编译器里应该算在同一数量级，所以能通过，严格说，较大的数组应该不在复杂度要求内