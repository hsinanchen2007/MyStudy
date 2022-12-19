执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :36.9 MB, 在所有 java 提交中击败了89.07%的用户
```
class Solution {
    public void nextPermutation(int[] nums) {
        if(nums == null || nums.length < 2)
            return;
        boolean flag = true;
        int index = 0;
        for(int i = nums.length-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                flag = false;
                index = i;
                break;
            }
        }
        if(flag){
            reverse(nums, 0, nums.length-1);
            return;
        }
        for(int i = nums.length-1; i >= 0; i--){
            if(nums[index] < nums[i]){
                swap(nums, index, i);
                break;
            }
        }
        reverse(nums, index+1, nums.length-1);
    }
    public void reverse(int[] nums, int start, int end){
        while(start < end)
            swap(nums, start++, end--);
    }
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```

