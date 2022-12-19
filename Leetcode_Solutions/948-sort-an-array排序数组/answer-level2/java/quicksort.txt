题目意图应该不是让直接调built-in sort
按照java sorting的实现对于primitive type采用dual-pivot quick sort
这里就简单实现了快排

```
class Solution {
    public int[] sortArray(int[] nums) {
        quicksort(nums, 0, nums.length-1);
        return nums;
    }
    
    void quicksort(int[] nums, int left, int right) {
        if (left >= right) return;
        int mid = partition(nums, left, right);
        
        quicksort(nums, left, mid-1);
        quicksort(nums, mid+1, right);
    }
    
    int partition(int[] nums, int left, int right) {
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i+1, right);
        return  i+1;
    }
    
    void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
