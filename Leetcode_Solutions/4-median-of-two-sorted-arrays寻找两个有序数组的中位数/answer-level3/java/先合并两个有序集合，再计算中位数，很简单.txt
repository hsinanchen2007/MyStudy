### 解题思路
先合并两个有序集合，再计算中位数，很简单

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int index1 = 0;
        int index2 = 0;
        int[] temp = new int[nums1.length + nums2.length];
        while (index1 < nums1.length && index2 < nums2.length) {
            if (nums1[index1] < nums2[index2]) {
                temp[index1 + index2] = nums1[index1];
                index1++;
            } else {
                temp[index1 + index2] = nums2[index2];
                index2++;

            }
        }
        while (index1 < nums1.length) {
            temp[index1 + index2] = nums1[index1];
            index1++;
        }
        while (index2 < nums2.length) {
            temp[index1 + index2] = nums2[index2];
            index2++;
        }
        if (temp.length % 2 == 0) {
            return (temp[(temp.length / 2 - 1)] + temp[(temp.length / 2)]) / 2.0;
        } else {
            return temp[(temp.length / 2 + temp.length % 2 - 1)];
        }
    }
}
```