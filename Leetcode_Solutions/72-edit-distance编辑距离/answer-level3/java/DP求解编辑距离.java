```java
class Solution {
    public int minDistance(String word1, String word2) {
        if(word1.length() == 0 && word2.length() == 0){
            return 0;
        }
        if(word1.length() != 0 && word2.length() == 0){
            return word1.length();
        }
        if(word1.length() == 0 && word2.length() != 0){
            return word2.length();
        }
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m][n];
        boolean isRepeat = false;//之前是否有重复字母
        //例如 abab b
        //word1第二个b之前已经有了一个b，重复了，重复后，就应该执行删除操作，操作数+1
        //不计重复 dp[i][0] = {1,1,2,2}
        //记得重复 dp[i][0] = {1,1,2,3} //最后一个b是删除操作
        for(int i = 0; i < m ; i++){//word2只有一个字母的话
            if(i == 0){
                if(word1.charAt(i) != word2.charAt(0)){
                    dp[i][0] = 1;
                }else{
                    dp[i][0] = 0;
                    isRepeat = true;
                }
            }else{
                if(isRepeat == true){
                    dp[i][0] = dp[i-1][0] + 1;
                    continue;
                }
                if(word1.charAt(i) != word2.charAt(0)){
                    dp[i][0] = dp[i-1][0] + 1;//对word1进行删除操作或者替换操作
                }else{
                    dp[i][0] = dp[i-1][0];
                    isRepeat = true;
                }
            }
        }
        isRepeat = false;
        for(int j = 0; j < n; j++){//word1只有一个字母的话
            if(j == 0){
                if(word1.charAt(0) != word2.charAt(j)){
                    dp[0][j] = 1;//对word1进行添加操作或者替换操作
                }else{
                    dp[0][j] = 0;
                    isRepeat = true;
                }
            }else{
                if(isRepeat == true){
                    dp[0][j] = dp[0][j-1] + 1;
                    continue;
                }
                if(word1.charAt(0) != word2.charAt(j)){
                    dp[0][j] = dp[0][j-1] + 1;
                }else{
                    dp[0][j] = dp[0][j-1];
                    isRepeat = true;
                }                
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(word1.charAt(i) == word2.charAt(j)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = Math.min(dp[i-1][j-1], dp[i-1][j]);
                    dp[i][j] = Math.min(dp[i][j], dp[i][j-1]);
                    dp[i][j] += 1;
                }
            }
        }
        return dp[m-1][n-1];
    }
}
```
