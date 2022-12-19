### 解题思路
快排的 partition 思想
不稳定，但不影响本题，对于有相同元素的情形同样适用
T: O(N)
N: O(1)

### 代码

```c
int partition (int nums[], int low, int high) {
    int pivot = nums[low];

    while (low < high) {
        while (low < high && nums[high] <= pivot) --high;
        nums[low] = nums[high];
        while (low < high && nums[low] > pivot) ++low;
        nums[high] = nums[low];
    }

    nums[low] = pivot;
    return low;
}

int findKthLargest(int* nums, int numsSize, int k){
    int low = 0;
    int high = numsSize - 1;
    int pivotPos = partition(nums, low, high);

    while ((pivotPos + 1) != k) {
        if ((pivotPos + 1) < k) low = pivotPos + 1;
        else high = pivotPos - 1;
        pivotPos = partition(nums, low, high);
    }

    return nums[pivotPos];
}
```