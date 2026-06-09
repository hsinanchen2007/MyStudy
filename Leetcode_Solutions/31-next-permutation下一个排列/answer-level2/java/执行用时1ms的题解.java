### 解题思路
1.这道题没有介绍什么是字典序，建议百度了解下，不然只看题会没思路
设计思路：
    1.从数组右侧向左开始遍历，找是否存在nums[i]>nums[i-1]的情况，
    2.如果不存在这种nums[i]>nums[i-1]情况 ，for循环会遍历到i==0（也就是没有下一个排列），此时按题意排成有序Arrays.sort()
    3.如果存在，则将从下标i到nums.length()的部分排序，然后在排过序的这部分中遍历找到第一个大于nums[i-1]的数，并与nums[i-1]交换位置

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
         int len = nums.length;
        for (int i = len - 1; i >= 0; i--) {
            if (i == 0) {
                Arrays.sort(nums);
                return;
            } else {
                if (nums[i] > nums[i - 1]) {
                    Arrays.sort(nums, i, len);
                    for (int j = i; j <len; j++) {
                        if (nums[j] > nums[i - 1]) {
                            int temp = nums[j];
                            nums[j] = nums[i - 1];
                            nums[i - 1] = temp;
                            return;
                        }
                    }
                }
            }
        }
    }
}
```