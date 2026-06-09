### 解题思路
此处采用了二维数组解决，难点在于状态（长串的首尾相同，它的子串的状态是否相同）的传递，

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
       int len=s.length();
       if(len<2){return s ;}
       boolean [][]dp=new boolean[len][len];
       // 将二维数组中全部放入true；
        for(int i=0;i<len;i++){
            dp[i][i]=true;
        }
        
        int maxLen=1;
        int start=0;
        for(int j=1;j<len;j++){
            for(int i=0;i<j;i++){
                if(s.charAt(i)==s.charAt(j)){
                    if(j-i<3){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }else{
                    dp[i][j]=false;
                }
                if(dp[i][j]){
                    int curLen=j-i+1;
                    if(curLen>maxLen){
                        maxLen=curLen;
                        start=i;
                    }
                }
            }
        }
        return s.substring(start,start+maxLen);
    }
}
```