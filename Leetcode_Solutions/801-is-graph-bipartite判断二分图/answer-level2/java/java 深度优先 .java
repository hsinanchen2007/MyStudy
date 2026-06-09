二分图： 有边的两个顶点应该是属于不同的类别，遍历的起始位置任意给定一个类别，当再次遍历这个点时，与预期的类别相同则继续，否则标记为非二分图；
为避免孤立点，需以每个点为起始点尝试，该算法存在的缺陷，要等遍历完所有的节点才返回结果

```

class Solution {
    int [] isVisited;
    boolean ret = true;
    int[][]graph;
    public boolean isBipartite(int[][] graph) {
        isVisited = new int[graph.length];
        Arrays.fill(isVisited,-1);
        this.graph = graph;
        for(int i = 0; i < graph.length; i++){
            if(isVisited[i] == -1){
                dfs(i,0);
            }
        }
        return ret;
    }
    // 
    void dfs(int i,int needed){
        if(isVisited[i] == -1){
            isVisited[i] = needed;
        }else if(isVisited[i] == needed){
            return;
        }else{
            ret = false;
            return;
        }
        for(int j = 0; j < graph[i].length;j++){
            if(needed == 1){
                dfs(graph[i][j],0);
            }else{
                dfs(graph[i][j],1);
            }
            
        }
    }
}
```
