### 解题思路
此处撰写解题思路
1.合并两个有序的数组，时间复杂度为O(m+n)
2.中位数算法

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] allNums = merge(nums1, nums2);
        return median(allNums);
    }

    public int[] merge(int[] nums1, int[] nums2) {
        if (nums1 == null || nums1.length == 0) {
            return nums2;
        }
        if (nums2 == null || nums2.length == 0) {
            return nums1;
        }

        int[] allNums = new int[nums1.length + nums2.length];
        int i = 0;
        int a = 0; 
        int b = 0;
        while(a < nums1.length && b < nums2.length) {
            if (nums1[a] <= nums2[b]) {
                allNums[i++] = nums1[a++];
            } else {
                allNums[i++] = nums2[b++];
            }
        }

        while (a < nums1.length) {
            allNums[i++] = nums1[a++];
        }
        while (b < nums2.length) {
            allNums[i++] = nums2[b++];
        }
        return allNums;
    }

    public double median(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0d;
        }
        int index = nums.length / 2;
        if (nums.length % 2 == 0) {
            return ((double) nums[index - 1] + nums[index]) / 2;
        } else {
            return (double) nums[index];
        }
    }
}
```