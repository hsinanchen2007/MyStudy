
```java []
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if(s == 0 && nums.length == 0){
            return 0;
        }
        
        int sum = 0;
        int ans = Integer.MAX_VALUE;  
        //这个是Integer类中的一个int类型的常量MAX_VALUE  它代表int所能表示的最大值 0x7FFFFFFF
        for(int i = 0,j = 0; i < nums.length; i++){
            while(j < nums.length && sum < s){
                sum += nums[j];
                j++;
            }
            
            if(sum >= s){
                ans = Math.min(ans, j - i);
            }
            sum -= nums[i];
        }
        
        if(ans == Integer.MAX_VALUE){
            ans = 0;
        }
        return ans;
    }
}
```
时间复杂度O（n）

