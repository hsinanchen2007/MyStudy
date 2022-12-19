### 解题思路
参考Dijkstra's算法的实现，优化算法结构:
1. 使用graph[K]替代了Dist数组
2. 将松弛和寻找最近节点合并在一个循环中

![微信截图_20200226205537.png](https://pic.leetcode-cn.com/48d225d51e03d5e31429a251bfc53c193085e3a0ae0752a8d1d78a561addf41d-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200226205537.png)


### 代码

```java
class Solution {
    private final int INF=0X3F3F3F3F;
    public int networkDelayTime(int[][] times, int N, int K) {
        int[][] graph = new int[N + 1][N + 1];
        for(int i = 1; i <= N; i++){//构建图
            for(int j = 0; j <= N; j++){
                graph[i][j] = i == j? 0: INF;
            }
        }
        for(int[] edge: times){
            graph[edge[0]][edge[1]] = edge[2];
        }

        boolean[] checked = new boolean[N + 1];
        for(int minN = K, newMin = 0; minN > 0; minN = newMin){//实现Dijkstra's，松弛与寻找最近节点合并进行。
            checked[minN] = true;
            newMin = 0;
            for(int j = 1; j < N + 1; j++){
                graph[K][j] = Math.min(graph[K][j], graph[K][minN] + graph[minN][j]);
                if(!checked[j] && graph[K][j] < graph[K][newMin]){
                    newMin = j;
                }
            }
        }

        int res = -1;
        for(int j = 1; j <= N; j++){
            res = Math.max(res, graph[K][j]);
            if(res == INF) return -1;
        }
        return res;
    }
}



```