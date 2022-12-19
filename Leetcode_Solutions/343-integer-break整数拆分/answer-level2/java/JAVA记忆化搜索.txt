拿到题如果没有做过类似的，或者立马有思路的可以先从暴力法思考，之后可根据具体条件进行优化
```
public int integerBreak(int n) {
    	int[] nums = new int[n+1];
    	return dfs(n,nums);
    }
    public int dfs(int num,int[] nums) {
    
    	if(num==1)
    		return 1;
    	if(nums[num]!=0)
    		return nums[num];
    	int tmp =Integer.MIN_VALUE;
    	for(int i = 1 ;i<=num-1;i++) {
    		int res = dfs(num-i,nums);
    		//将num进行分割至少两部分
    			tmp = Math.max(tmp, Math.max(res*i,i*(num-i)));

    	}
    	nums[num] = tmp;
    	return tmp;
    }
```
