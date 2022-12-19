dp[i][j]表示将前i个字符组成的字符串分割成j个子串所需改变的字符个数
toS()返回将字符串变成回文所需改变的字符个数
```
class Solution {
    public int palindromePartition(String s, int k) {
        int length=s.length();
        int[][] dp = new int[length+1][k+1];
        // 初始化数组,赋上较大的值
        for(int i=0;i<length+1;i++){
            for (int j=0;j<k+1;j++){
                dp[i][j]=length;
            }
        }
        // 初始化dp[i][1],即将字符串分割成1个(不分割)
        for (int i=1;i<=length;i++){
            dp[i][1]=toS(s.substring(0,i));
        }
        // 依次计算分割2次到k次
        for (int i=2;i<=k;i++){
            // 分割i次时dp[][i]值
            for(int j=length;j>=i;j--){
                // 遍历取最小值
                for(int x=1;x<=j-i+1;x++){
                    dp[j][i]=Math.min(dp[j-x][i-1]+toS(s.substring(j-x,j)),dp[j][i]);
                }
            }

        }
        return dp[length][k];
    }
    public static int toS(String s){
        int a=0;
        for (int i=0;i<s.length()/2;i++){
            if(s.charAt(i)!=s.charAt(s.length()-1-i)){
                a++;
            }
        }
        return a;
    }
}
```
