```
class Solution {
    /*************************************

    DP
    
    **************************************/
    public int minHeightShelves(int[][] books, int shelf_width) {
        int m = books.length;
        int n = shelf_width;

        // corner case 
        if (m == 1) {
            return books[0][1];
        }

        int[] dp = new  int[m+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int  i = 1; i <= m; i++) {
            int height = 0;
            int width = 0;

            int j = i;
            while (j > 0) {
                width += books[j-1][0];
                if (width > n) break;
                height = Math.max(books[j-1][1], height);
                dp[i] = Math.min(dp[i], dp[j-1] + height);
                j--;
            }           
        }

        return dp[m];
    }   
}
```
