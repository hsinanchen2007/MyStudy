执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :34.9 MB, 在所有 java 提交中击败了46.10%的用户
```
class Solution {
    public void sortColors(int[] nums) {
        if(nums == null || nums.length < 2)
            return;
        int start = -1;
        int end = nums.length;
        int cur = 0;
        while(cur < end){
            if(nums[cur] == 0){
                swap(nums, ++start, cur++);
            }
            else if(nums[cur] == 1){
                cur++;
            }
            else{
                swap(nums, --end, cur);
            }
        }
    }
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
