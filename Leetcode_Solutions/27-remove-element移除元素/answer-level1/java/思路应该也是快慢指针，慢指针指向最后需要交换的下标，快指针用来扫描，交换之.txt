```
class Solution {
    public int removeElement(int[] nums, int val) {
        int j = nums.length - 1;
        for (int i=nums.length-1;i>=0;i--){
            if (nums[i] == val){
                swap(nums,i,j);
                j--;
            }
        }
        return j+1;
    }
    private void swap(int[] nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
