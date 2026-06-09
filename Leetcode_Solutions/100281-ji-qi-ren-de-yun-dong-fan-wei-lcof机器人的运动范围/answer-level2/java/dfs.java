### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int M, N;
    private int direction[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int movingCount(int m, int n, int k) {
        M = m;
        N = n;
        int max = 0;
        boolean visited[][] = new boolean[M][N];
        int res = dfs(0, 0, k, 1, visited);
        // for(int i = 0; i < M; i++){
        //     for(int j = 0; j < N; j++){
        //         int res = dfs(i, j, k, 0);
        //         max = Math.max(max, res);
        //     }
        // }
        return res;
    }

    private int dfs(int r, int c, int k, int distance, boolean[][] visited){
        
        if(r >= M || r < 0 || c >= N || c < 0 || visited[r][c]){
            return 0;
        }
        int sum = 0;
        if(r >= 10){
            if(r == 100){
                sum += 1 + 0 + 0;
            }else{
                int temp = r / 10;
                int ge = r - temp * 10;
                sum += temp + ge;
            }
        }else{
            sum += r;
        }

        if(c >= 10){
            if(c == 100){
                sum += 1 + 0 + 0;
            }else{
                int temp = c / 10;
                int ge = c - temp * 10;
                sum += temp + ge;
            }
        }else{
            sum += c;
        }
        if(sum > k){
            return 0;
        }

        visited[r][c] = true;
        for(int[] d: direction){
            int nextr = d[0] + r;
            int nextc = d[1] + c;
            int res = dfs(nextr, nextc, k, distance + 1, visited);
            distance = Math.max(res, distance);
        }
        return distance;
    }
}
```