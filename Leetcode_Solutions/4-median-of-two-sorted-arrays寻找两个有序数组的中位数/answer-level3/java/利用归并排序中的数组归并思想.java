### 解题思路
利用归并排序中的归并思想，将两个有序数组归并为一个有序数组
![微信图片_20200315151701.jpg](https://pic.leetcode-cn.com/0d815bfeeed485ea3f507d86bae4dc3ced4fa336ee6eb72ce1a77114395a4646-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200315151701.jpg)



### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int current1 = 0;
        int current2 = 0;
        int[] result = new int[nums1.length + nums2.length];
        int index = 0;

        while(current1 < nums1.length && current2 < nums2.length) {
            if (nums1[current1] < nums2[current2]) {
                result[index++] = nums1[current1++];
            }
            else {
                result[index++] = nums2[current2++];
            }
        }

        while (current1 < nums1.length) {
            result[index++] = nums1[current1++];
        }

        while (current2 < nums2.length) {
            result[index++] = nums2[current2++];
        }

        if (result.length % 2 != 0) {
            return (double)result[result.length / 2];
        }
        else {

            double x = (double)result[result.length / 2];
            double y = (double)result[result.length / 2 - 1];
            return (x + y) / 2;
        }
    }
}
```