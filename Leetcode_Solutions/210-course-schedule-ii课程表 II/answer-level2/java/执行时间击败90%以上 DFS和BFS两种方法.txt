### 解题思路
解题思路看具体代码

1、BFS
### 代码

```java
import java.util.ArrayList;


class Solution {

    ArrayList<Integer>[] graph;  // 邻接表graph[i]表示有哪些顶点与i相邻
    boolean[] visited;  // visited[i]表示顶点i有没有被访问过，在本题中，可能存在多个连通分量，所以设置visited，可以减少重复访问，提高效率
    boolean[] stack;    // 保存在一次dfs中某顶点是否被访问过，记得回溯的时候要设置stack[i]为false
    int[] res;  // 用来进行保存答案
    int size;   // 答案中已经含有多少个元素了

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // 构建图
        graph = new ArrayList[numCourses];
        for(int i=0; i<numCourses; i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] pre: prerequisites){
            graph[pre[0]].add(pre[1]);
        }

        // 对visted和stack进行初始化
        visited = new boolean[numCourses];
        stack = new boolean[numCourses];
        res = new int[numCourses];
        size = 0;

        // 对各个顶点分别进行dfs，但是进行之前先看该节点有没有被访问过，避免重复访问，提高效率
        for(int v=0; v<numCourses; v++){
            if(!visited[v] && haveCycle(v)){
                return new int[0];
            }
        }

        return res;
    }

    // 对顶点v进行dfs
    private boolean haveCycle(int v){
        visited[v] = true;
        stack[v] = true;

        // 对顶点v的邻边进行遍历
        for(int w:graph[v]){
            if(visited[w] && stack[w]) return true;
            if(visited[w]) continue;
            if(haveCycle(w)) return true;
        }

        stack[v] = false;
        res[size++] = v;
        
        return false;
    }
}
```

2、DFS，也即拓扑排序
```
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 方法：dfs
 */
class Solution {

    int[] res;  // 设置一个列表来保存顶点
    int size;  // 来表示res中已经有多少顶点了
    ArrayList<Integer>[] graph;  // 使用邻接表来存储图
    int[] in;  // 保存顶点的入度

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // 获得graph和in
        graph = new ArrayList[numCourses];
        for(int i=0; i<numCourses; i++){
            graph[i] = new ArrayList<>();
        }
        in = new int[numCourses];
        res = new int[numCourses];
        size = 0;

        // 遍历prerequisites
        for (int[] pre: prerequisites){
            graph[pre[1]].add(pre[0]);
            in[pre[0]] ++;
        }

        // BFS操作
        Queue<Integer> queue = new LinkedList<>();  // 设置一个队列来保存入度为0的顶点
        for(int i=0; i<numCourses; i++){
            if(in[i] == 0){
                queue.add(i);
            }
        }
        while(!queue.isEmpty()){
            int v = queue.remove();
            res[size++] = v;
            // 对v的邻边进行遍历
            for(int w: graph[v]){
                if(--in[w] == 0){
                    queue.add(w);
                }
            }
        }

        if(size != numCourses){
            return new int[0];
        }
        return res;
    }
}

```
