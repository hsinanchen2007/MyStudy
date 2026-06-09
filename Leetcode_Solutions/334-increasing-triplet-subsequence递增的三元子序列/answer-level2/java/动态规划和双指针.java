动态规划：
执行用时 :111 ms, 在所有 java 提交中击败了7.97% 的用户
内存消耗 :38.6 MB, 在所有 java 提交中击败了75.44%的用户
```
class Solution {
    public boolean increasingTriplet(int[] nums) {
        if(nums == null || nums.length < 3)
            return false;
        int[] dp = new int[nums.length];
        dp[0] = 0;
        for(int i = 1; i < nums.length; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
                if(dp[i] > 1)
                    return true;
            }
        }
        return false;
    }
}
```


双指针：
执行用时 :1 ms, 在所有 java 提交中击败了99.24% 的用户
内存消耗 :38.8 MB, 在所有 java 提交中击败了72.59%的用户
```
class Solution {
    public boolean increasingTriplet(int[] nums) {
        if(nums == null || nums.length < 3)
            return false;
        int min = Integer.MAX_VALUE;
        int mid = Integer.MAX_VALUE;
        for(int num : nums){
            if(num <= min){
                min = num;
            }
            else if(num <= mid){
                mid = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
}
```
