
```c++
    int maxSizeSlices(vector<int>& slices) {
         int n = slices.size();
         vector<vector<int>> dp1 (n+1, vector<int>(n+1, 0)); 
         vector<vector<int>> dp2 (n+1, vector<int>(n+1, 0));

         dp1[1][1] = slices[0]; //拿第一个
         dp2[1][1] = 0; //不拿第一个
         
         for(int i=2; i<=n; i++){
             for(int j=1; j<=min(i, n/3); j++){
                 if(i<n) //dp1不拿最后一个
                    dp1[i][j] = max(dp1[i-1][j], dp1[i-2][j-1] + slices[i-1]);
                dp2[i][j] = max(dp2[i-1][j], dp2[i-2][j-1] + slices[i-1]); //dp2可以拿最后一个
             }
         }

         return max(dp1[n-1][n/3], dp2[n][n/3]);
    }
```