### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] array = new int[nums1.length + nums2.length];
        int maxlenth = nums1.length + nums2.length;
        int i = 0, j = 0,m = 0;
        while (i < nums1.length || j < nums2.length) {
            if (i >= nums1.length) {
                array[m++] = nums2[j++];
                continue;
            }
            if (j >= nums2.length) {
                array[m++] = nums1[i++];
                continue;
            }
            array[m++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];

        }
        int tag = maxlenth / 2;
        if (maxlenth % 2 == 0) {
            return (array[tag - 1] + array[tag]) / 2.0;
        } else {
            return array[tag];
        }
    }
}
```