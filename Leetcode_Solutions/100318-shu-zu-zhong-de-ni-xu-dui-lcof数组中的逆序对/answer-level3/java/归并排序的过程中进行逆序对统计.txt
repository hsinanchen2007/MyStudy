### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reversePairs(int[] nums) {
        int[] temp = new int[nums.length];
        return mergeSort(nums, 0, nums.length, temp);
    }

    // 原数组进行归并排序，在归并过程中统计逆序对数
    // 注意：不重用temp数组的情况下会超内存、超时间
    public int mergeSort(int[] nums, int start, int end, int[] temp) {
        int middle = (start + end) / 2;

        int countLeft = start < middle ? mergeSort(nums, start, middle, temp) : 0; // 归并排序半个数组
        int countRight = (middle > start && middle < end) ? mergeSort(nums, middle, end, temp) : 0; // 归并排序右半个数组

        // 此次左右两半数组都是排序好的
        int leftIndex = start;
        int rightIndex = middle;
        int count = 0;
        for (int i = start; i < end; i++) {
            // 比较大小的四种情况
            if (leftIndex >= middle) {
                temp[i] = nums[rightIndex];
                rightIndex++;
            } else if (rightIndex >= end) {
                temp[i] = nums[leftIndex];
                leftIndex++;
            } else if (nums[leftIndex] <= nums[rightIndex]) {
                temp[i] = nums[leftIndex];
                leftIndex++;
            } else {
                temp[i] = nums[rightIndex];
                rightIndex++;
                // 此时nums[leftIndex] 到nums[middle]的数都比nums[rightIndex]大，都能组成逆序对；
                count += middle - leftIndex;
            }
        }
        // 要把temp的值填回nums中
        for (int i = start; i < end; i++) {
            nums[i] = temp[i];
        }
        return count + countLeft + countRight;
    }
}
```