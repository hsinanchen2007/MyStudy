```
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)return 0;
        Arrays.sort(nums);
        int i = 0;
        int j = 0;
        int max = 1;
        for(j = 1;j < nums.length;j++){
            if(nums[j] == nums[j - 1] + 1){
                max = Math.max(j - i + 1,max);
            }
            else if(nums[j] == nums[j - 1]){
                i++;
            }
            else{
                i = j;
            }
        }
        return max;
    }
}
```
