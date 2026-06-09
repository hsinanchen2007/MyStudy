由于需要对这k个数排序，所以这道题直接先对原数组排序，使用大顶堆也是可以实现的。
```
class Solution {
    public int[] smallestK(int[] arr, int k) {
        quicksort(arr);
        if (k == arr.length)
            return arr;
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i)
            ans[i] = arr[i];
        
        return ans;
    }
    
    private void quicksort(int[] nums) {
        quicksort(nums, 0, nums.length - 1);
    }
    
    private void quicksort(int[] nums, int left, int right) {
        if (left >= right)
            return;
        int key = nums[left], l = left, r = right;
        while (l < r) {
            while (l < r && nums[r] >= key)
                r--;
            while (l < r && nums[l] <= key)
                l++;
            if (l < r)
                nums[l] = nums[l] + nums[r] - (nums[r] = nums[l]);
        }
        
        nums[left] = nums[l];
        nums[l] = key;
        quicksort(nums, left, l - 1);
        quicksort(nums, l + 1, right);
    }
}
```
