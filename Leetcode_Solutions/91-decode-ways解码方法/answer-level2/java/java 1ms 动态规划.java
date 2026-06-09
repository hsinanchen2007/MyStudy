```
class Solution {
    //动态规划，dp[i]表示以第i个数结尾的一串码字的解码方法数量
    //其实还可以优化空间复杂度的，算法只需用到了数组的前两个元素
    //根据这一点可以用两个变量代替整个数组
    //我懒得写了
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        int pre = s.charAt(0) - '0';
        if(pre == 0) return 0;
        dp[0] = 1;
        for(int i=1; i<s.length(); i++){
            int cur = s.charAt(i) - '0';
            //注意遇到0的情况
            if(cur==0){
                //如果前一个数字也是0或者前一个数字和当前的0无法组合成一个有效的码字
                //则break，退出循环，返回的dp[s.length()-1]自然就是0了。
                if(pre==0 || pre>2) break;
                //如果是码字有效的，则还要判断当前索引是不是1
                //如果当前索引是1，则dp[i] = 1
                //否则dp[i] = dp[i-2]
                if(i>1) dp[i] = dp[i-2];
                else dp[i] = 1;
            }
            else{
                //当前数字可以和前一位数字组成一个有效的码字
                if(pre!=0 && pre*10+cur<=26){
                    //注意当前索引是否为1的两种情况
                    //索引不为1时，状态转移方程如下
                    if(i>1) dp[i] = dp[i-1]+dp[i-2];
                    else dp[i] = dp[i-1] + 1;
                }
                //当前数字可以和前一位数字不能组成一个有效的码字 
                else dp[i] = dp[i-1];
            } 
            
            pre = cur;
        }
        return dp[s.length()-1];
    }
}
```
