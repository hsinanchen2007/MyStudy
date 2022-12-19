### 解题思路
大概把几种排序算法都实现了一遍

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        // 选择排序
        selectSort(nums);
        // 冒泡排序
        bubbleSort(nums);
        // 插入排序
        insertSort(nums);
        // 归并排序
        mergeSort(nums, 0, nums.length - 1);
        // 快排
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    void selectSort(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int min = nums[i];
            int swap = i;
            for (int j = i; j < nums.length; j++) {
                if (nums[j] < min) {
                    swap = j;
                    min = nums[j];
                }
            }
            nums[swap] = nums[i];
            nums[i] = min;
        }
    }
    void bubbleSort(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
    void insertSort(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int j = i - 1;
            int temp = nums[i];
            while (j >= 0 && temp < nums[j]) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = temp;
        }
    }
    void mergeSort(int[] nums, int begin, int end) {
        if (begin >= end) return;
        int middle = (begin + end) / 2;
        mergeSort(nums, begin, middle);
        mergeSort(nums, middle + 1, end);
        merge(nums, begin, end);
    }

    void merge(int[] nums, int begin, int end) {
        int[] temp = new int[end - begin + 1];
        int middle = (begin + end) / 2;
        int i = begin, j = middle + 1, k = 0;
        while (k < end - begin + 1) {
            if (i == middle + 1) {
                temp[k] = nums[j];
                j++;
            } else if (j == end + 1) {
                temp[k] = nums[i];
                i++;
            } else if (nums[i] < nums[j]) {
                temp[k] = nums[i];
                i++;
            } else {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }
        for (int h = 0; h < end - begin + 1; h++) {
            nums[begin + h] = temp[h];
        }
    }
    void quickSort(int[] nums, int begin, int end) {
        if (begin >= end) return;
        int temp = nums[end];
        int left = begin, right = end;
        while (left < right) {
            while (left < right && nums[left] <= temp) left++;
            if (left < right) nums[right] = nums[left];
            while (left < right && nums[right] >= temp) right--;
            if (left < right) nums[left] = nums[right];
        }
        nums[left] = temp;
        quickSort(nums, begin, left - 1);
        quickSort(nums, left, end);
    }
}
```