这道题描述轻飘飘一句求两个有序数组的中位数，其实理解了差不多也就有思路了。

首先，这两个数组是有序的，其次，我们要知道他的中位数。那么，怎么做呢？

答案是归并排序中的核心Merge动作，我们将两个有序数组合并成一个大的有序数组，然后对这个合并后的有序数组进行中位数求值。

合并后的中位数，其实就是看一个数组的中间那个数，如果数组长度是奇数，那直接就是len/2，如果是偶数，那就是len / 2和其左边那个数的和的一半了

```java
public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] total = new int[nums1.length + nums2.length];
        int i = 0;
        int firstIndex = 0;
        int secondIndex = 0;
        double result;
        int len = total.length;
        while (firstIndex < nums1.length && secondIndex < nums2.length) {
            if (nums1[firstIndex] <= nums2[secondIndex]) {
                total[i] = nums1[firstIndex];
                ++firstIndex;
                ++i;
            } else {
                total[i] = nums2[secondIndex];
                ++secondIndex;
                ++i;
            }
        }

        if (secondIndex == nums2.length) {
            while (i < total.length) {
                total[i] = nums1[firstIndex];
                ++firstIndex;
                ++i;
            }
        } else if (firstIndex == nums1.length) {
            while (i < total.length) {
                total[i] = nums2[secondIndex];
                ++secondIndex;
                ++i;
            }
        }

        if (len % 2 == 0) {
            result = (double) (total[len / 2] + total[len / 2 - 1]) / 2;

        } else {
            result = total[len / 2];
        }

        return result;
    }
```

![image.png](https://pic.leetcode-cn.com/c2990d1d484687d650778e6bd1bb45a3445922ff305839405b0d8250efeadc10-image.png)
