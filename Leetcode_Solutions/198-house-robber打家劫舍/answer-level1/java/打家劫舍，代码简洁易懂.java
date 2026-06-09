
    
![QQ截图20191124100450.png](https://pic.leetcode-cn.com/21bcdd46dc611c3226baa2b62a6afe02cbd01832635992b68059f86a114db604-QQ%E6%88%AA%E5%9B%BE20191124100450.png)
    // 暴力递归,这也像子序列问题，可以先尝试用暴力递归进行求解，最后改成动态规划
    public int rob(int[] nums){
        return subRob(nums,0);
    }
    //暴力递归
    public int subRob(int[] nums,int level){
        if(level>=nums.length){
            return 0;
        }
        return Math.max(subRob(nums,level+1),nums[level]+subRob(nums,level+2));
    }

    //从暴力递归修改成动态规划，递归写完，直接可以不看题目，通过递归来写动态规划[]()
    public int robDP(int[] nums){
        int[] dp=new int[nums.length+2];
        dp[nums.length+1]=0;
        dp[nums.length]=0;
        for(int i=dp.length-3;i>=0;i--){
             dp[i]=Math.max(dp[i+1],nums[i]+dp[i+2]);  
        }
        return dp[0];
    }