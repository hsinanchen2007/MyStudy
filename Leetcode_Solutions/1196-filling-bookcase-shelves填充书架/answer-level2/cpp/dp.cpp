```
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1,1000000);
        dp[0] = 0;
        
        for(int i = 0;i < n; ++i){
            int width = 0;
            int height = 0;
            for(int j = i; j >= 0; --j){
                width += books[j][0];
                height = max(height,books[j][1]);
                if(width <= shelf_width){
                    dp[i+1] = min(dp[i+1],dp[j]+height);
                }else{
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
```