在一个有向图中有环的话一定无法完成所有课程
```
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] graph = new List[numCourses];
        for(int i = 0; i < numCourses; i++) graph[i] = new ArrayList<Integer>();
        for(int[] pre : prerequisites){
            graph[pre[1]].add(pre[0]);
        }
        int[] vis = new int[numCourses];
        for(int i = 0; i < numCourses; i++){
            if(dfs(i, vis, graph)) return false;
        }
        return true;
    }
    
    public boolean dfs(int cur, int[] vis, List<Integer>[] graph){
        if(vis[cur] == 2) return false;
        if(vis[cur] == 1) return true;
        vis[cur] = 1;
        for(int i : graph[cur]){
            if(dfs(i, vis, graph)) return true;
        }
        vis[cur] = 2;
        return false;
    }
}
```
