### 解题思路
二分查找。看到log 基本都是二分法.
 
![image.png](https://pic.leetcode-cn.com/acab79a49ceede37e215ccdc4f24d5f405f510fe19aeae3dc4e2112898d64da5-image.png)


### 代码

```python
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        # to ensure that nums1 <= nums2
        if len(nums1) > len(nums2):  
            temp = nums1
            nums1 = nums2
            nums2 = temp
        num_m, num_n  = len(nums1), len(nums2)
        if num_n == 0:
            raise ValueError
        half_len_mn = (num_m+num_n+1)/2
        # print num_m, num_n, half_len_mn

        i_min = 0
        i_max = num_m
        max_left = 0
        min_right = 0

        while i_min <= i_max:
            # print 'step0'
            # print i_min, i_max
            ind_i = (i_max + i_min) / 2
            ind_j = half_len_mn - ind_i
            print ind_i, ind_j
            print nums1, nums2

            if ind_i < num_m and nums2[ind_j-1] > nums1[ind_i] :
                # print 'step1'
                i_min = ind_i + 1
            elif ind_i > 0 and nums1[ind_i-1] > nums2[ind_j]:
                # print 'step2'
                i_max = ind_i - 1
            else:
                # print 'step3'
                if ind_i == 0: max_left = nums2[ind_j-1]
                elif ind_j == 0: max_left = nums1[ind_i-1]
                else: max_left = max(nums2[ind_j-1], nums1[ind_i-1])

                if (num_m+num_n)%2 == 1:
                    # print max_left, min_right
                    return max_left

                if ind_i == num_m: min_right = nums2[ind_j]
                elif ind_j == num_n: min_right = nums1[ind_i]
                else: min_right = min(nums2[ind_j], nums1[ind_i])

                # print max_left, min_right
                return (max_left + min_right) / 2.0
```