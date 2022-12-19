### 解题思路
唉
### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s.length()==0)
            return "";
        int[][] dp=new int[s.length()][s.length()];
        HashMap<Integer,String>pList=new HashMap<>();
        int Max=0,sum=0;
        String res="";
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                if(s.charAt(i)==s.charAt(j)){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=0;i<s.length();i++){
            for(int k=0;k<2;k++){
                for(int gap=(k==0?1:0);i-k-gap>=0&&i+gap<dp.length;gap++){
                    if(dp[i-k-gap][i+gap]==0)
                        break;
                    sum++;
                    res+=s.charAt(i+gap);
                }
                sum=(k==0?sum*2+1:sum*2);
                if(Max<=sum){
                    if(k==0)
                        res=new StringBuilder(res).reverse().toString()+s.charAt(i)+res;
                    else
                        res=new StringBuilder(res).reverse().toString()+res;
                    Max=sum;
                    pList.put(Max,new String(res));
                }
                sum=0;
                res="";
            }
        }
        return pList.get(Max);
    }
}
```