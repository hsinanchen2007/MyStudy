### 解题思路
每进行一次快排partition，可以确定pivot的最终位置，若是题中要求的位置，则终止；
否则根据pivot与目标位置的大小关系来决定下一次是在哪一边（pivot的左/右）寻找。

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int targetPos = nums.length - k;
        int left = 0;
        int right = nums.length - 1;
        while (true) {
            int posOfPivot = partition(nums, left, right);
            if (posOfPivot == targetPos) {
                return nums[posOfPivot];
            } else if (posOfPivot > targetPos) {
                right = posOfPivot - 1;
            } else {
                left = posOfPivot + 1;
            }
        }
    }

    public int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && nums[j] > pivot) {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }
}
```