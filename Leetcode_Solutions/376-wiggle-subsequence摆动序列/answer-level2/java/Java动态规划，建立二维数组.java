### 解题思路
建立二维数组dp[nums.length][2],第二维分别代表与前一个相减为正或者为负

### 代码

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length < 2){
            return nums.length;
        }
        
        int dp[][] = new int[nums.length][2];
        dp[0][0] = 1;
        dp[0][1] = 1;
        
        int max = 0;
        for(int i = 1; i < nums.length; i++){
            
            for(int j = i-1; j >= 0; j--){
                if(nums[i] > nums[j]){
                    dp[i][1] = Math.max(dp[i][1], dp[j][0] + 1);
                    max = Math.max(max, dp[i][1]);
                }else if(nums[i] < nums[j]){
                    dp[i][0] = Math.max(dp[i][0], dp[j][1] + 1);
                    max = Math.max(max, dp[i][0]);
                }else{
                    dp[i][1] = Math.max(dp[i][1], dp[j][1]);
                    max = Math.max(max, dp[i][1]);
                    dp[i][0] = Math.max(dp[i][0], dp[j][0]);
                    max = Math.max(max, dp[i][0]);
                }
                
            }
        }
        return max;
    }
}
```