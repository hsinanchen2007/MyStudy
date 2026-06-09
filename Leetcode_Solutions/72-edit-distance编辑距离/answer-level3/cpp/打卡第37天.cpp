练习
```
class Solution {
public:
    int minDistance(string word1, string word2) {
      const int m = word1.size();
      const int n = word2.size();
    
        int **dp = new int*[m+1];
        for(int i=0;i<m+1;i++){
             dp[i]= new int[n+1];
        }
        for(int i=0;i<m+1;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<n+1;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                
                }else{
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i][j]);   
                    
                
            }
        }
        return dp[m][n];
        
    }
};

```
