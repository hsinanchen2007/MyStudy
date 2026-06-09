### 解题思路
快排中如果选到了目标值，就马上返回

### 代码

```java
// 找len-k位置的数 , 利用快排
class Solution {
    int k_;

    public int findKthLargest(int[] nums, int k) {
        this.k_ = nums.length - k;
        return partition(nums, 0, nums.length - 1);
    }

    // 确定一个值的位置
    public int partition(int[] nums, int left, int right) {
        int pivotTemp = left + ((right - left) >> 1);
        int pivot = right;
        int temp = nums[pivotTemp];
        nums[pivotTemp] = nums[pivot];
        nums[pivot] = temp;
        // i: 插入  j: 待定
        int i = left, j = left;
        for (; j < right; j++) {
            if (nums[j] < nums[pivot]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++; // 插入位置更新
            }
        }
        // pivot
        temp = nums[i];
        nums[i] = nums[pivot];
        nums[pivot] = temp;
        if (k_ == i) {
            return nums[i];
        } else if (k_ < i) {
            return partition(nums, left, i - 1);
        } else { // k_>i
            return partition(nums, i + 1, right);
        }
    }
}
```