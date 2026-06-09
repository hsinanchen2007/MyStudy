### 解题思路
对于两个有序数组而言，每次干掉一个最小值，干掉一个最大值，循环(nums1.length + nums2.length - 1) / 2次，如果有一个数组为空，则跳出循环。
如果有一个数组为空，则可以直接计算另一个数组的中位数即可；
如果两个数组都不为空，此时每个数组正好各剩一个数，求这两个数的平均数即可。

### 代码

```java
class Solution {
   public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int times = (nums1.length + nums2.length - 1) / 2;
        int start1 = 0;
        int end1 = nums1.length - 1;
        int start2 = 0;
        int end2 = nums2.length - 1;
        for (int i = 0; i < times && end1 >= start1 && end2 >= start2; i++) {
            //去掉一个最小值
            if (nums1[start1] < nums2[start2]) {
                start1++;
            } else {
                start2++;
            }
            //去掉一个最大值
            if (end1 < start1) {
                end2--;
            } else if (end2 < start2) {
                end1--;
            } else if (nums1[end1] < nums2[end2]) {
                end2--;
            } else {
                end1--;
            }
        }
        if (end1 < start1) {
            int len = (end2 - start2) / 2;
            return (nums2[start2 + len] + nums2[end2 - len]) * 0.5;
        }
        if (end2 < start2) {
            int len = (end1 - start1) / 2;
            return (nums1[start1 + len] + nums1[end1 - len]) * 0.5;
        }
        return (nums1[start1] + nums2[start2]) * 0.5;
    }
}
```