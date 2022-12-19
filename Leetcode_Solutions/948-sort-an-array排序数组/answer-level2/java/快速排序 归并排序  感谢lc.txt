### 解题思路
学习了  感谢lc   

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }

    public void mergeSort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int cur = 0;
        int[] tmp = new int[right - left + 1];
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[cur++] = nums[i++];
            } else {
                tmp[cur++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cur++] = nums[i++];
        }
        while (j <= right) {
            tmp[cur++] = nums[j++];
        }
        for (int k = 0; k < tmp.length; k++) {
            nums[left++] = tmp[k];
        }
    }

    private void quickSort(int[] nums, int i, int j) {
        if (i >= j) {
            return;
        }
        int lo = i + 1;
        int hi = j;
        while (lo <= hi) {
            if (nums[lo] > nums[i]) {
                swap(nums, lo, hi);
                hi--;
            } else {
                lo++;
            }
        }
        lo--;
        swap(nums, i, lo);
        quickSort(nums, i, lo - 1);
        quickSort(nums, lo + 1, j);
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```