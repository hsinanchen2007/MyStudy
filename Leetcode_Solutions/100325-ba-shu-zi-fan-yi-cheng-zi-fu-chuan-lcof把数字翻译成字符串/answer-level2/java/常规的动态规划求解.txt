```
class Solution {
    public int translateNum(int num) {
        //将数字转化为数组
        String str = String.valueOf(num);//num为需要转化的整数
        int len=str.length();
        int[] nums = new int[str.length()];
        for(int i=0;i<str.length();i++){
            nums[i]=Integer.parseInt(String.valueOf(str.charAt(i)));
        }
        if(len<=1)return len;
        int[] dp=new int[len+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=len;i++){//判断当前连续的两位是否在10-25之间
            if(nums[i-2]*10+nums[i-1]>25||nums[i-2]*10+nums[i-1]<10){
                dp[i]=dp[i-1];
            }else{
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[len];
    }
}
```
