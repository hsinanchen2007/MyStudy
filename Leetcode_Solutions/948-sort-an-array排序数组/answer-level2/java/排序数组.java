### 解题思路
此题最好的就是用Arrays sort一下就完事了，可明显不符合出题用意。排序的方法很多，这里简单用堆排序来实现。

### 代码

```java
class Solution {
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void maxHeapify(int[] nums, int index, int len) {
        int left = (index << 1) + 1;
        int right = left + 1;
        int max = index;
        if (left < len && nums[left] > nums[max]) {
            max = left;
        }
        if (right < len && nums[right] > nums[max]) {
            max = right;
        }
        
        if (max != index) {
            swap(nums, max, index);
            maxHeapify(nums, max, len);
        }
    }

    public int[] sortArray(int[] nums) {
        for (int i = nums.length / 2; i >= 0; i--) {
            maxHeapify(nums, i, nums.length);
        }

        for (int i = nums.length - 1; i > 0; i--) {
            swap(nums, 0, i);
            maxHeapify(nums, 0, i);
        }
        return nums;
    }
}
```