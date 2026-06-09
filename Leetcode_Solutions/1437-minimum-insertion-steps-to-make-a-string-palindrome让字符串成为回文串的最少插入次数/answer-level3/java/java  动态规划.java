### 解题思路
区间动态规划，二维数组保存dp状态，dp[i][j]表示下标i到下标j的字符串的最少插入次数

dp分两种情况：
    1、s.charAt(i)==s.charAt(j) 此时不需要计算，取其内部字符串的值就行
    2、s.charAt(i)！=s.charAt(j) 分两种情况，去较小值
        此时要么是右边添加字符s.charAt(i)  dp[i+1][j] + 1, 
        要么左边添加字符s.charAt(j)  dp[i][j-1]+1
### 代码

```java
class Solution {
    public int minInsertions(String s) {
        int len = s.length();
        int[][] dp = new int[len][len];
        
        for(int i=len-1 ; i>=0 ; i--){
            for(int j=i+1; j<len ; j++){
                if(s.charAt(i)==s.charAt(j)){
                    dp[i][j] = dp[i+1][j-1];
                } else{
                    dp[i][j] = Math.min(dp[i+1][j],dp[i][j-1])+1;
                }
            }
        }
        
        return dp[0][len-1];
    }
}
```