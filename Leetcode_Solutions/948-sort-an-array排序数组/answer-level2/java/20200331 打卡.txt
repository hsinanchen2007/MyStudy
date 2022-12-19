### 解题思路
归并排序

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
       if (nums.length < 2) {
            return nums;
        }
        int[] copy = new int[nums.length];
        mergeCore(nums, copy, 0, nums.length - 1);
        return nums;
    }
    public static void mergeCore(int[] array, int[] copy, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) >> 1;
        mergeCore(array, copy, left, mid);
        mergeCore(array, copy, mid + 1, right);
        int i = mid;
        int j = right;
        int copyLoop = right;
        while (i >= left && j > mid) {
            if (array[i] > array[j]) {
                copy[copyLoop--] = array[i--];
            } else {
                copy[copyLoop--] = array[j--];
            }
        }
        while (i >= left) {
            copy[copyLoop--] = array[i--];
        }
        while (j > mid) {
            copy[copyLoop--] = array[j--];
        }
        for (int n = left; n <= right; n++) {
            array[n] = copy[n];
        }
    }
}
```
快速排序

```java
 public int[] sortArray(int[] nums) {
        quickSort(nums,0,nums.length-1);
        return nums;
    }

    public void quickSort(int[] nums, int left, int right) {
        if (left < right) {
            int mid = partion(nums, left, right);
            quickSort(nums, left, mid - 1);
            quickSort(nums, mid + 1, right);
        }
    }

    public int partion(int[] nums, int left, int right) {
        int tmp = nums[left];
        while (left < right) {
            while (right > left && nums[right] >= tmp) right--;
            nums[left] = nums[right];
            nums[right] = tmp;
            while (left < right && nums[left] <= tmp) left++;
            nums[right] = nums[left];
            nums[left] = tmp;
        }
        return left;
    }
```