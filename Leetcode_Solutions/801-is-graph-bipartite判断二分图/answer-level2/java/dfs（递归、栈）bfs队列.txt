### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[][] graph;
    int[] visited;

    public boolean isBipartite(int[][] graph) {
        this.graph = graph;
        visited = new int[graph.length];
        for(int i=0;i<graph.length;i++)
            if(visited[i]==0 && !dfs(i)) return false;
        return true;  
    }
    //用栈的话，事实上，每个递归的传入参数都得给父亲保存起来（否则就得自己保存到栈里，儿子从栈中拿，要么天生带上，不能只利用栈给访问排序而不给保证传入的参数，这里是父亲的颜色）
    boolean dfs(int cur){
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(cur);
        visited[cur] = 1;
        while(!stack.isEmpty()){
            cur = stack.pop();     
            for(int i : graph[cur]){
                if(visited[i] == 0){
                    stack.push(i);
                    visited[i] = -visited[cur];//老父亲也不能帮你保存，只能老父亲帮你设置好到外部
                }else if(visited[i] == visited[cur])
                    return false;
            }  
        }
        return true;
    }
}

//图的深度优先用递归解就是最好的了，儿子管自己，别让老父亲帮你判断合法不，函数栈帧自己保存自己参数，有多少存多少，手动栈模拟的话最好只保存顺序，不要保存一堆参数，
class Solution {
    int[][] graph;
    int[] visited;

    public boolean isBipartite(int[][] graph) {
        this.graph = graph;
        visited = new int[graph.length];
        for(int i=0;i<graph.length;i++)//非连通，只需要每个部分满足每一条边的两个节点一个来自A集合，一个来自B集合也算二分图
            if(visited[i]==0 && !dfs(i,1)) return false;//公用一个visited数组，已经访问过的就是已经上色的，也是就是连通的就跳过
        return true;
    }
    boolean dfs(int cur, int color){
        if(visited[cur] != 0) return visited[cur] == color;

        visited[cur] = color;
        for(int i: graph[cur]){
            if(!dfs(i, -color)) return false;
        }
        return true;
    }
}

//bfs
class Solution {
    int[][] graph;
    int[] visited;

    public boolean isBipartite(int[][] graph) {
        this.graph = graph;
        visited = new int[graph.length];
        for(int i=0;i<graph.length;i++)
            if(visited[i]==0 && !bfs(i)) return false;
        return true;  
    }

    boolean bfs(int cur){
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(cur);
        visited[cur] = 1;
        while(!queue.isEmpty()){
            cur = queue.remove();     
            for(int i : graph[cur]){
                if(visited[i] == 0){
                    queue.add(i);
                    visited[i] = -visited[cur];//老父亲也不能帮你保存，只能老父亲帮你设置好到外部
                }else if(visited[i] == visited[cur])
                    return false;
            }  
        }
        return true;
    }
}
```