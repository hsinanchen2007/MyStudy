```
/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2) {
    var n1 = text1.length
    var n2 = text2.length
    var dp = new Array(n1 + 1)
    for(var i = 0; i <= n1; i++){
        dp[i] = new Array(n2 + 1)
        dp[i][0] = 0
        
    }
    for(var i = 0;i <= n2; i++){
        dp[0][i] = 0
    }
    for(var i = 1;i <= n1; i++){
        for(var j = 1;j <= n2; j++){
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1
            }else{
                dp[i][j] = Math.max(dp[i - 1][j],dp[i][j - 1])
            }
        }
    }
    return dp[n1][n2]

    

};
```
