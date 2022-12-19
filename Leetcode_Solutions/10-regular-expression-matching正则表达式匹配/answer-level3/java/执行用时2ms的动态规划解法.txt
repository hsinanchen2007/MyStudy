```
//第一次写题解有点不会写QAQ
//dp[i][ii]为1时表示p的前i个字符与s的前ii个字符相匹配
class Solution {
    public boolean isMatch(String s, String p) {
        int[][] dp = new int[p.length()+10][s.length()+10];
        dp[0][0] = 1;
        for(int i = 0; i < p.length(); i++){
            char now = p.charAt(i);//now记录现在的字符,其值一定不会是*
            int flag = 0;//记录下一个字符是否是*
            if(i+1 < p.length() && p.charAt(i+1) == '*'){
                i++;//对i进行递增，把*字符和它前面的一个字符视为一体
                flag = 1;
                //任何字符和*搭配数量都可能为0,所以在不包括这两个字符时如果能和s中前ii个字符匹配的话那么加上这两个字符一定也可以
                for(int ii = 0; ii <= s.length(); ii++){
                    if(dp[i-1][ii] == 1){
                        dp[i+1][ii] = 1;//i是星号在数组中的下标，根据数组的特性星号是数组的第i+1个字符
                    }
                }
            }
            //不含星号时的状态转移方程，若p的前i个字符成功匹配s的前ii个字符且两者的第i+1和ii+1个字符也相互匹配则进行状态转移
            if(flag == 0){
                for(int ii = 0; ii < s.length(); ii++){
                    if(dp[i][ii] == 1 && (now == '.' || now == s.charAt(ii))){
                        dp[i+1][ii+1] = 1;
                    }
                }
            }
            /*含星号时的状态转移，区别是if语句的前半部分，判断dp[i-1][ii] == 1与不含星号时情况相同
            但因为之前把星号和它所属的字符视为一体所以i要减1跳过星号所属字符，判断dp[i+1][ii] == 1
            是因为星号无限匹配的特性，虽然星号所属字符已经在上一次循环匹配s[ii-1]了但只要和s[ii]依旧
            相等则可继续匹配进行状态转移*/
            else{
                for(int ii = 0; ii < s.length(); ii++){
                    if((dp[i+1][ii] == 1 || dp[i-1][ii] == 1) && (now == '.' || now == s.charAt(ii))){
                        dp[i+1][ii+1] = 1;//s[ii]为s的第ii+1个字符
                    }
                }
            }
        }
        if(dp[p.length()][s.length()] == 1){
            return true;
        }
        else{
            return false;
        }
    }
}
```
