参考了[link](https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/yu-zhi-ju-chi-nei-lin-ju-zui-shao-de-cheng-shi-by-/)，
算法分成 3 步骤实现
1. 遍历每个顶点，以每个顶点为出发点到达图中其他顶点的最短路径
2. 子方法中， 遍历当前顶点的所有最短路径的长度， filter 掉路径长度 大于 阈值上限（distanceThreshold） 的最短路径，将满足要求的路径 ++
3. 将当前顶点的最短路径总数和全局变量比较，如果当前最短路径总数较小，就更新全局变量，然后使用 ans 同步存放当前顶点
 最后留下的顶点 ans 就是 经历顶点最少，且以其为出发点的最短路径长度 小于等于阈值上限的顶点


`class Solution {
    // graph 存放图结构
    private int [][] graph;
    // 存放最终结果
    private int ans;
    // 存放图中所有顶点中最短路径加权长度 小于 阈值上线的顶点个数
    private int minNodeCount = Integer.MAX_VALUE;
    
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        graph = new int [n][n];
        // init graph 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = -1;
            }
        }

        // init graph by edges 
        for (int [] edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
        }

        // traverse each node and find its shortest path 
        // minNodeCount used to store path with minimum nodes
        for (int start = 0; start < n ; start++) {
            djkstra(start, n, distanceThreshold);
        }
        return ans;
    }

       void djkstra(int src, int n, int threshold) {
        // create local variables 
        int [] distances = new int [n];
        boolean [] visited = new boolean [n];

        // init local variables 

        Arrays.fill(distances, -1);
        distances[src] = 0;
        visited[src] = true;

        // traverse other n -1 vertexs
        for (int i = 0; i < n-1; i++) {
            int minDistance = Integer.MAX_VALUE;
            int minIndex = 1;

            // find from remained && unvisited nodes the nearest node 
            for (int j = 0; j < n; j++) {
                if (!visited[j] && distances[j] != -1 && distances[j] < minDistance) {
                    minDistance = distances[j];
                    minIndex = j;
                }
            }

            visited[minIndex] = true;

            // update distances between 
            for (int j = 0; j < n; j++) if (graph[minIndex][j] != -1) {
                if (distances[j] != -1) {
                    distances[j] = Math.min(distances[j], distances[minIndex] + graph[minIndex][j]);
                } else {
                    distances[j] = distances[minIndex] + graph[minIndex][j];
                }
                
            }
        } // for 

        // traverse distancs first filter src's shortest path's distance length > threashold
        // then count current vertex src how many spf it has 
        int counter = 0;
        for (int i = 0; i < distances.length; i++) {
            if (distances[i] != -1 && distances[i] < threshold) {
                counter++;
            }
        } 

         System.out.printf("vertex: %d, counter: %d\n", src, counter);
         
        // update value to global 
        if (counter < minNodeCount) {
           
            minNodeCount= counter;
            ans = src;
        }
    }
}`