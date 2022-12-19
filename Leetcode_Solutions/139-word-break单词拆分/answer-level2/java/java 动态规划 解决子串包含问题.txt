### 解题思路
假设我们有一个State dp[][],其中dp[i][j]表示字符串从i到j是否可以被wordbreak
那么这个State就有三个状态,true,false,unkown;

所以我们可以建立一个辅助函数
//其中start表示当前在大字符串s的某个起始位置,s表示当前要校验的子串,maxLength表示大字符串的长度
private boolean helpBreak(String s,int start,List<String> wordDict,int maxLength){

}

//这里的dp[0][i]表示满足包含在wordDict里的第一个符合条件的字符串
这样我们可以得到状态方程dp[0][s.length] = dp[o][i] + helpBreak(s.substring(i,s.length,i,wordDict,maxLength))。

接下里我们实现这个辅助函数
private boolean helpBreak(String s,int start,List<String> wordDict,int maxLength){
        if(dp[start][start+s.length] != State.unkown){
                return     dp[start][start+s.length()]  == State.True?true:false;
        }
        int length = s.length();
        for(int i = 0;i<=s.length;i++){
                    if(wordDict.contains(s.subString(0,i))){
                                dp[start][start+i] = State.true;
                                String lastString = s.subString(i,length);
                                if(helpBreak(lastString,i+start,wordDict,maxLength){
                                            return true;
                                }else{
                                         dp[start+i][maxLength] = State.false;
                                }
                    }else{
                            dp[start][start+i] = State.false;
                    }
        }
        return false;
}

### 代码

```java
class Solution {

        private enum State{
        TRUE,
        UNKOWN,
        FALSE
    }
    private State[][] dp ;

    public boolean wordBreak(String s, List<String> wordDict) {
        dp = new State[s.length()+1][s.length()+1];
        for(int i = 0;i<dp.length;i++){
            for(int j = 0;j<dp.length;j++){
                dp[i][j] = State.UNKOWN;
            }
        }
        boolean wordBreak = helpWordBreak(s, 0, wordDict,s.length());
        return wordBreak;
    }



    /**
     * 假设dp[i][j]表示[i,j)的字符串是否能wordBreak,那么dp[0][i] = dp[0][i-1] && [i-1,i)也在里面
     * 最后就是求dp[0][s.length]是否为true
     *
     *
     * 从左至右先找到能最大包含的字符串,然后对剩余的字符串进行循环调用
     *
     * @param s
     * @param wordDict
     * @return
     */
    public boolean helpWordBreak(String s,int start, List<String> wordDict,int maxLength) {
        if(s==null||s.length()==0 || wordDict==null || wordDict.isEmpty()){
            return false;
        }
        if(dp[start][start+s.length()] != State.UNKOWN){
            return dp[start][start+s.length()]==State.TRUE?true:false;
        }
        if(wordDict.contains(s)){
            return true;
        }
        int length = s.length();
        for(int i = 0;i<=length;i++){
            if(wordDict.contains(s.substring(0,i))){
                dp[start][i+start] = State.TRUE;
                String lastString = s.substring(i,length);
                if(helpWordBreak(lastString,i+start,wordDict,maxLength)){
                    return true;
                }else{
                    dp[start+i][maxLength] = State.FALSE;
                }
            }else{
                dp[start][i+start] = State.FALSE;
            }
        }
        return false;
    }

}
```