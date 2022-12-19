### 解法一 动态规划 
```
class Solution {
    public int minDistance(String word1, String word2) {
        int word1Length=word1.length();
        int word2Length=word2.length();
        if(word1Length==0) return word2Length;
        if(word2Length==0) return word1Length;
        //一维表示word1前i个的字符
        //二维表示word2前j个的字符
        //值表示word1前i个的字符要转成word2前j个的字符所使用的最少操作数。
        int[][] dp=new int[word1Length+1][word2Length+1];
        //设置初始值.
        for(int i=0;i<=word2Length;i++){
            //word1为null的情况，那要形成word2，只能不停的插入。
            dp[0][i]=i;
        }
        for(int j=0;j<=word1Length;j++){
            //word2为null的情况，word1只能不停的删除自身的字符.
            dp[j][0]=j;
        }
        for(int i=1;i<=word1Length;i++){
            for(int j=1;j<=word2Length;j++){
                //假设word1到i个字符与word2到j字符已经完全匹配了。
                //那么最后一步有几种操作?
                //1.如果word1第i-1位置字符与word2第j-1位置字符，正好一样，则不需要做额外的操作.操作数不变。
                //注意这边下标的取值，word1是从0开始的。而i和j代表的是字母个数。i=0代表word1是null的，i=1代表的是word1[0];
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                //2.如果不一样，则有三种操作可能.
                //1.最后一步插入之后，word1与word2才匹配。
                //要想在插入之后从word1[0~i]与word2[0~j]匹配，说明word1[0~i]与word2[0~j-1]是匹配的,只不过word1还少最后一个字母，加上就匹配。
                    int ins=dp[i][j-1]+1;
                //2.最后一步是删除，删除之后word1[0~i]与word2[0~j]匹配。说明word1[0~i-1]与word2[0~j]就是匹配的，只不过word1多一个字母，删掉就匹配。
                    int del=dp[i-1][j]+1;
                //3.最后一步是替换,说明word1[0~i-1]与word2[0~j-1]就是匹配的，只不过最后一个字母不匹配,所以要做一个替换
                    int rep=dp[i-1][j-1]+1;
                    //取三个操作中的最小值。
                    dp[i][j]=Math.min(Math.min(ins,del),rep);
                }
            }
        }
        return dp[word1Length][word2Length];
    }
}
```
