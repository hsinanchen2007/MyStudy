内存时间双击败90+
```
public class Solution {

    int[] head ;
    Edge[] edges;
    int cnt = 0;
    int[] vis;

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        edges = new Edge[prerequisites.length+1];
        head = new int[numCourses];
        vis = new int[numCourses];
        for (int i = 0; i < head.length; i++) {
            head[i] = -1;
        }
        for (int[] prerequisite : prerequisites) {
            addEdge(prerequisite[0],prerequisite[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if(dfs(i)==false)
                return false;
        }
        return true;
    }

    private boolean dfs(int i) {
        if(vis[i]==1) return true;
        if(vis[i]==-1) return false;
        vis[i] = -1;
        for(int v = head[i];v!=-1;v = edges[v].next){
            int to = edges[v].to;
            if(dfs(to)==false){
                return false;
            }
        }
        vis[i] = 1;
        //ans.add(i);如果要实现拓扑排序，在这里加一句话就行。
        return true;
    }

    private void addEdge(int u, int v) {
        edges[cnt] = new Edge();
        edges[cnt].to = v;
        edges[cnt].next = head[u];
        head[u] = cnt++;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        boolean b = solution.canFinish(2, new int[][]{ new int[]{1, 0}});
        System.out.println(b);
    }
}

class Edge{
    int to;
    int next;
}
```
