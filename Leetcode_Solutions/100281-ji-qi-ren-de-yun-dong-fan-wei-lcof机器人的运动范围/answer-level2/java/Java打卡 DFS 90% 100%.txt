个人习惯：在写DFS喜欢用void，然后将状态、结果记录在类的成员变量中。

```Java [深度遍历搜索]
import java.util.*;

public class Solution {
    private int m;
    private int n;
    private int k;
    private int count;
    private boolean[][] marked;

    public int movingCount(int m, int n, int k) {
        this.m = m;
        this.n = n;
        this.k = k;
        count = 0;
        marked = new boolean[m][n];

        dfs(0, 0);

        return count;
    }

    private void dfs(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || bitSum(x, y) > k) return;

        if (!marked[x][y]) {
            marked[x][y] = true;
            ++count;
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        }
    }

    private static int bitSum(int i, int j) {
        int sum = 0;
        while (i > 0) {
            int mod = i % 10;
            sum += mod;
            i /= 10;
        }
        while (j > 0) {
            int mod = j % 10;
            sum += mod;
            j /= 10;
        }
        return sum;
    }
}
```
