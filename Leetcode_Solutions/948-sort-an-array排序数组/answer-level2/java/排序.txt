### 解题思路
归并排序

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }
    private void mergeSort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int[] tmp = new int[right - left + 1];
        int l1 = left;
        int l2 = mid + 1;
        int index = 0;
        while (l1 <= mid && l2 <= right) {
            if (nums[l1] <= nums[l2]) {
                tmp[index++] = nums[l1++];
            } else {
                tmp[index++] = nums[l2++];
            }
        }
        while (l1 <= mid) {
            tmp[index++] = nums[l1++];
        }
        while (l2 <= right) {
            tmp[index++] = nums[l2++];
        }
        for (int i = 0; i < tmp.length; i++) {
            nums[left + i] = tmp[i];
        }
    }
}
```