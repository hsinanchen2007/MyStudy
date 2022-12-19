```
class Solution {
    //第一种：递归：毫无疑问超时
    public int rob(int[] nums) {
        //偷第一个房间，最后一个房间不能偷，设置一个状态flag
        //偷i : tou[i] = nums[i] + tou[i + 2]
        //不偷i: bu[i] = tou[i + 1]
        //取得max
        return process(nums,0,true);
    }
    
    public int process(int[] nums,int i,boolean flag){
        if(i >= nums.length){
            return 0;
        }
        
        if(i == nums.length - 1 && flag == false){
            return 0;
        }
        
        
        int n2 = process(nums,i + 1,flag);
        if(i == 0){
            flag = false;
        }
        int n1 = nums[i] + process(nums,i + 2,flag);
        
        return Math.max(n1,n2);
    }
	
    //第二种：两个一维数组
    public int rob(int[] nums) {

        
        int n = nums.length;
        
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        int[] dp1 = new int[n];//偷最后一家
        dp1[n - 1] = nums[n - 1];
        dp1[n - 2] = Math.max(nums[n - 1], nums[n - 2]);
        int[] dp2 = new int[n];//不偷最后一家
        dp2[n - 2] = nums[n - 2];

        for(int i = n - 3; i >= 0; i--){
            dp1[i] = Math.max(nums[i] + dp1[i + 2],dp1[i + 1]);
            dp2[i] = Math.max(nums[i] + dp2[i + 2],dp2[i + 1]);
        }
        return Math.max(dp1[1],dp2[0]);
    }
	
    //第三种：第二种的优化
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        
        //第一种方案：偷最后一家
        int a2 = nums[n - 1];
        int a1 = Math.max(nums[n - 1],nums[n - 2]);
        int ans1 = a2;

        //第二种方案：不偷最后一家
        int b2 = 0;
        int b1 = nums[n - 2];
        int ans2 = b1;
        
        
        for(int i = n - 3; i >= 0; i--){
            ans1 = Math.max(nums[i] + a2,a1);
            a2 = a1;
            a1 = ans1;
            ans2 = Math.max(nums[i] + b2,b1);
            b2 = b1;
            b1 = ans2;
        }
        return Math.max(a2,ans2);
    }
	
    //第四种：
    //分别对0 ~ n-1 和 1 ~ n-2 做动态规划
	
}
```
