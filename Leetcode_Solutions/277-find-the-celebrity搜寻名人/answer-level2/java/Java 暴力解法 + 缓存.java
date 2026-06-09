从 0 到n - 1循环一次，假设 i 为名人，看是否符合条件。过程中用一个二维数组缓存结果。

```
/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        if (n <= 1) {
            return -1;
        }
        int[][] cache = new int[n][n];
        for(int i = 0; i < n; i ++) {
            boolean isCelebrity = true;
            // suppose i is celebrity 
            for (int j = 0; j < n; j ++) {
                if (i == j) {
                    continue;
                }
                if (help(i, j, cache)) {
                    isCelebrity = false;
                    break;
                }
                if (!help(j, i, cache)) {
                    isCelebrity = false;
                    break;
                }
            }
            if (isCelebrity) {
                return i;
            }
        }
        return -1;
    }

    public boolean help(int i, int j, int[][] cache) {
        if (cache[i][j] != 0) {
            return cache[i][j] == 1;
        }
        boolean ans = knows(i, j);
        cache[i][j] = ans ? 1 : -1;
        return ans;
    }

}
```
