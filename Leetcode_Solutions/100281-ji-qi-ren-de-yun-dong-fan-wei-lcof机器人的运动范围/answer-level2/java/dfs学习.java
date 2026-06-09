### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        boolean visited[][] = new boolean[m][n];
        return dfs(0, 0, m, n, k, visited);
    }
    public int dfs(int i, int j, int m, int n, int k, boolean visited[][]){
        if (i < 0 || i>= m || j < 0 || j >= n || visited[i][j] 
        || (!isLowerToK(i, j, k))) return 0;
        visited[i][j] = true;
        return dfs(i - 1, j, m, n, k, visited) + dfs(i + 1, j, m, n, k, visited) + 
        dfs(i, j - 1, m, n, k, visited) + dfs(i, j + 1, m, n, k, visited) + 1;
    }
    public boolean isLowerToK(int i, int j, int k){
        int x, sum = 0;
        for (x = i ; x > 0 ; x /= 10) sum += x % 10;
        for (x = j ; x > 0 ; x /= 10) sum += x % 10;
        return sum <= k;
    }
}
```