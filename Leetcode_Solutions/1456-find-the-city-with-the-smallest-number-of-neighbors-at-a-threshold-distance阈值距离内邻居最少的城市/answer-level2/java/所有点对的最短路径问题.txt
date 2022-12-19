### 解题思路
用的动态规划，网上一查就有。
主要别忘了在初始化，没有路径的点之间要初始化为+无穷。

### 代码

```java
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] map = new int[n][n];
        //int[][] dp  = new int[n][n];
        for(int i=0;i<edges.length;i++){
            map[edges[i][0]][edges[i][1]]=edges[i][2];
            map[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(map[i][j]==0){
                        map[i][j] = 100000;
                    }
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    map[i][j] = Math.min(map[i][j],map[i][k]+map[k][j]);
                }
            }
        }
        int mind = n;
        int min = 0;
        //int comin = 0
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(map[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mind){
                mind = count;
                min = i;
            }
        }
        return min;
    }
}
```