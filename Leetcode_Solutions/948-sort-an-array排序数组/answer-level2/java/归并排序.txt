### 解题思路
1、拆分-拆分为两元组或更小，排序
2、合并-排序后的数组


### 代码

```java
class Solution {

    public int[] sortArray(int[] nums) {
        //Arrays.sort(nums);
        help(nums, 0, nums.length - 1);
        return nums;
    }

    private void help(int[] nums, int start, int end) {
        if (start == end) return;
        if (start + 1 == end) {
            if (nums[end] < nums[start]) {
                swap(nums, start, end);
            }
            return;
        }
        int mid = (start + end) / 2;
        help(nums, start, mid);
        help(nums, mid + 1, end);
        merge(nums, start, mid, end);

    }

    private void merge(int[] nums, int start, int mid, int end) {
        int[] leftNums = Arrays.copyOfRange(nums, start, mid + 1);
        int[] rightNums = Arrays.copyOfRange(nums, mid + 1, end + 1);
        int l = leftNums.length;
        int r = rightNums.length;
        if (l == 0) return;
        if (r == 0) return;
        int i = start;
        int leftIndex = 0;
        int rightIndex = 0;
        while (i < start + l + r) {
            if (leftIndex == l) {
                nums[i] = rightNums[rightIndex];
                rightIndex++;
            } else if (rightIndex == r) {
                nums[i] = leftNums[leftIndex];
                leftIndex++;
            } else if (leftNums[leftIndex] >= rightNums[rightIndex]) {
                nums[i] = rightNums[rightIndex];
                rightIndex++;
            } else {
                nums[i] = leftNums[leftIndex];
                leftIndex++;
            }
            i++;
        }

    }

    private void swap(int[] nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }


}
```