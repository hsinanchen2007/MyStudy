```
class Solution {
    public int translateNum(int num) {
        String nums = String.valueOf(num);

        if(nums.length()==1) return 1;
        if(nums.length()==2){
            if(nums.compareTo("25")>0) return 1;
            return 2;
        }
        int[] dp = new int[nums.length()+1];
        dp[1] =1;
        if(nums.substring(0,2).compareTo("25")>0) dp[2] = 1;else dp[2] = 2;
        for (int i = 3; i <=nums.length() ; i++) {
            //0和后面的数不可以合并在一起
            if(nums.substring(i-2,i).compareTo("25")>0||nums.substring(i-2,i).compareTo("10")<0)
                dp[i] = dp[i-1];
            else dp[i] = dp[i-2]+dp[i-1];
        }
        return dp[nums.length()];
    }
}
```
