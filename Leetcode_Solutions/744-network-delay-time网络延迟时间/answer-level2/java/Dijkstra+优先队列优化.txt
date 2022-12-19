### 解题思路
题目意思是从源点出发，需要多久才能同时到达所有顶点。只需要求出源点到各个顶点的最短路，再取其中的最大值即可。当存在不可到达的顶点时，说明图存在多个连通分量，返回-1.

这里我使用优先队列优化的Dijstra求最短路:)

### 代码

```java
class Solution {
    public final static int  INF = 6001;//最大距离值
    //边结点
    private class Node implements Comparable<Node>{
        public int v, dis;//表示源点到v的最短距离为ids

        public Node(int v, int dis) {
            this.v = v;
            this.dis = dis;
        }

        @Override
        public int compareTo(Node o) {
            return dis- o.dis;
        }
    }
    public int networkDelayTime(int[][] times, int N, int K) {
        if(N == 1) return 0;
        int dis[] = new int[N+1];   //源点到各顶点的最短距离
        boolean vis[] = new boolean[N+1]; //标记是否访问
        Arrays.fill(vis, false);
        Arrays.fill(dis,INF);

        //构图
        int [][]g = new int[N+1][N+1];
        for (int i = 1; i <= N; i++){
            Arrays.fill(g[i], INF);
            g[i][i] = 0;
        }

        for(int []p: times)
            g[p[0]][p[1]] = p[2];

        //优先队列
        Queue<Node> queue = new PriorityQueue<>();
        //初始，将源点添加进队列
        queue.add(new Node(K,0));
        dis[K] = 0;
        while (!queue.isEmpty()){
            int cur = (queue.remove()).v;
            if(vis[cur])continue;;
            vis[cur] = true;
            //遍历cur的邻接点
            for(int v = 1; v <= N; v++)
                if(!vis[v]){
                    //松弛
                    if(g[cur][v] + dis[cur] < dis[v]){
                        dis[v] = g[cur][v] + dis[cur];
                        queue.add(new Node(v,dis[v]));
                    }
                }
        }
        //最短距离的最大值即为答案
        int maxDis = -1;
        for(int i = 1; i <= N; i++){
            if(dis[i] == INF) return -1;//存在不可到达的顶点
            if(maxDis < dis[i]) maxDis = dis[i];
        }
        return maxDis;
    }
}
```




![screenshot.png](https://pic.leetcode-cn.com/1965df28d5d0a6f85d6d1dba4cf751076b8f660ea73d58a9460ee8fb01eed69a-screenshot.png)
