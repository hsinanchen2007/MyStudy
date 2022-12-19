### 解题思路
开始用动态规划做，说超出内存。然后用递归做，说超出时间限制。
最后用别人的方法做，做出来了。
==


### 代码

```java
class Solution {
    private int ans = 0;

    public void calculate(int n){
        if(n == 0)
            return;
        int x = n;
        while(x != 0){
            int left = x % 10;
            if(left == 1){
                this.ans += 1;
            }
            x = x / 10;
        }
        calculate(n-1); 
    }

    // public int countDigitOne(int n) {
    //     if(n <= 0)
    //         return 0;
        
    //     // int[] dp = new int[n+1];
    //     // dp[0] = 0;
        
    //     // for(int i = 1; i <= n; i++){
    //     //     int ans = 0;
    //     //     int x = i;
    //     //     while(x != 0){
    //     //         int left = x % 10;
    //     //         if(left == 1){
    //     //             ans += 1;
    //     //         }
    //     //         x = x / 10;
    //     //     }
    //     //     dp[i] = dp[i-1] + ans;
    //     // }
    //     // return dp[n];
    //     calculate(n);
    //     return this.ans;
    // }
     public int countDigitOne(int n) {
    	int cnt = 0;
	    int mul =1;
	    int left =n;
	    int right =0;
	    if(n==0) {
	    	return 0;
	    }
	    while(left>0) {
	    	int digit = left%10;
	    	left/=10;
	    	if(digit == 1) {
	    		cnt+=left*mul;
	    		cnt+=right+1;
	    	}
	    	else if(digit<1) {
	    		cnt+=left*mul;
	    	}
	    	else {
	    		cnt+=(left+1)*mul;
	    	}
	    	right+=digit*mul;
	    	mul*=10;
	    }
		return cnt;
    }

}
```