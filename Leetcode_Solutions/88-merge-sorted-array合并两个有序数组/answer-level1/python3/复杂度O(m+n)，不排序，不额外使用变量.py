思路：两个数列从后往前比较，比较出最大的依次从nums1的第m+n-1个往前放，如果遇到nums1最少数比nums2余下的都要小，就按nums2的排序放入nums1

```
while n > 0:
            if nums2[n-1] >= nums1[m-1]:
                nums1[m+n-1] = nums2[n-1]
                n = n - 1
            else:
                if m < 0:
                    nums1[n-1] = nums2[n-1]
                    n = n - 1
                else:
                    nums1[m+n-1] = nums1[m-1]
                    m = m - 1
        return nums1
```
