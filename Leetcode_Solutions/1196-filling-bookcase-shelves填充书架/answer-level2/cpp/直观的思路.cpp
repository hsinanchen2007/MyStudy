### 解题思路

动态规划，设dp[i]表示到books[i]（这里books的下标从1到n）为止的最小高度，只考虑如何构成书架的最后一排，即
$$
dp[i] = \min_k(dp[i-k] + maxHeight)
$$
maxHeight表示从books[i-k+1]到books[i]所有书中最高的高度，并且满足books[i-k+1]到books[i]加起来的厚度不超过书架，即能同时放在最后一层，最后输出$dp[n]$即可。

### 代码

```cpp
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int *dp = new int[books.size()+1];
        memset(dp, 0, sizeof(int)*(books.size()+1));
        
        for(int i = 1; i <= books.size(); i++)
        {
            int cur_width = 0;
            int cur_height = 0;
            int min_height = 1e8;
            for(int j = i; j > 0 && cur_width+books[j-1][0] <= shelf_width; j--)
            {
                cur_width += books[j-1][0];
                cur_height = max(cur_height, books[j-1][1]);
                min_height = min(min_height, cur_height+dp[j-1]);
            }
            dp[i] = min_height;
        }

        return dp[books.size()];
    }
};
```