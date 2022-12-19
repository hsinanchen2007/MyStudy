### 解题思路
解题讲解见https://www.bilibili.com/video/av79016033/

### 代码

```java
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * 思路：是否形成环
 */
class Solution {
    boolean[] visited;  // visited[i]表示顶点i有没有被访问过，要进行回溯操作的
    ArrayList<Integer>[] graph;
    boolean[] marked;  // 进行深度遍历的时候，标记哪些顶点已经访问过

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        visited = new boolean[numCourses];
        marked = new boolean[numCourses];

        // 先构建图，邻接表
        graph = new ArrayList[numCourses];  // numCourses表示表的大小
        for(int i=0; i<numCourses; i++){
            graph[i] = new ArrayList<>();
        }
        for(int i=0; i<prerequisites.length; i++){
            graph[prerequisites[i][0]].add(prerequisites[i][1]);
        }

        // dfs操作
        for(int v=0; v<numCourses; v++){
            if(!marked[v] && haveCycle(v)){
                return false;
            }
        }
        return true;
    }

    // 进行dfs操作 对顶点v的邻边进行深度优先遍历
    private boolean haveCycle(int v){
        visited[v] = true;
        marked[v] = true;

        // dfs
        for(int next: graph[v]){
            if(marked[next] && visited[next]) return true;  // 表示形成环路
            if(marked[next]) continue;
            if(haveCycle(next)) return true;  // next顶点形成环路，说明也形成环路
        }

        visited[v] = false;  // 回溯的时候应该重新设置为false

        return false;
    }
}
```