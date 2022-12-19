```
class Solution {
    public int massage(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int[][] count = new int[nums.length][2];
        count[0][0] = 0;
        count[0][1] = nums[0];
        for(int i = 1; i < nums.length; i++){
            int last_not = count[i-1][0];
            int last_yes = count[i-1][1];
            count[i][0] = Math.max(last_not, last_yes);
            count[i][1] = last_not + nums[i];
            
        }
       
        return Math.max(count[nums.length - 1][0], count[nums.length - 1][1]);
    }
}
```
