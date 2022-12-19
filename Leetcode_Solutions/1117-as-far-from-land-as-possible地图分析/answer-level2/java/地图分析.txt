### 解题思路
直接暴力，第一遍扫描出距离陆地最近距离是0或者1；第二遍扫描出2；第三遍扫描出3；······；直到没有了，就是最大值。。。复杂度有点高，感觉过不了。没想到java中6ms  100%,42.6MB 99%..

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int N = grid.length;

        int[][] dp = new int[N][N];
        int needToCount = 0;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (grid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if (grid[i][j] == 0){
                    if ((i-1>=0 && grid[i-1][j] == 1)
                            || (i+1<N && grid[i+1][j] == 1)
                            || (j-1>=0 && grid[i][j-1] == 1)
                            || (j+1<N && grid[i][j+1] ==1)){
                        dp[i][j] = 1;
                    } 
                    else {
                        dp[i][j] = -1;
                        needToCount++;
                    }
                }
            }
        }

        if (needToCount == 0 || needToCount == N*N){
            return -1;
        }
        int index = 1;
        while(needToCount > 0){
            for (int i=0;i<N;i++){
                for (int j=0;j<N;j++){
                    if (dp[i][j] == -1 ){
                        if ((i-1>=0 && dp[i-1][j] == index)
                                || (i+1<N && dp[i+1][j] == index)
                                || (j-1>=0 && dp[i][j-1] == index)
                                || (j+1<N && dp[i][j+1] ==index)){
                            dp[i][j] = index + 1;
                            needToCount--;
                        }
                    }
                }
            }
            index++;
        }

        return index;
    }
}
```