```java []
import java.util.Arrays;

import static java.lang.Math.*;

class Solution {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int[] dp = new int[books.length + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;//作用是第一本书时 min(dp[i], dp[0] + height) 可得出dp[1]
        for (int i = 1; i <= books.length; i++) {
            int height = 0;
            int width = 0;
            int j = i;
            while (j > 0) {
                width += books[j - 1][0];
                if (width > shelf_width) {
                    break;
                }
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
                j--;
            }
        }

        return dp[dp.length - 1];
    }
}
```

