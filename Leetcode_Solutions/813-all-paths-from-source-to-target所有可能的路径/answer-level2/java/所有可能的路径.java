### 方法一：深度优先搜索

#### 思路：
我们从起点$0$开始，对整张有向图进行深度优先遍历，同时记录途中经过的节点，当我们到达终点$N-1$时，我们把记录的路径加入结果数组中。

#### 算法：
- $path$存储我们途径的节点，当离开时将该节点从$path$数组中弹出。
- $visit$数组记录我们访问过的节点，以避免重复访问进入死循环。

```java []
class Solution {
    private List<List<Integer>> ans;
    private int[][] graph;
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        this.ans = new ArrayList<>();
        this.graph = graph;
        boolean[] visit = new boolean[graph.length];
        List<Integer> path = new ArrayList<>();
        
        DFS(0, path, visit);
        return ans;
    }
    private void DFS(int pos, List<Integer> path, boolean[] visit) {
        int N = graph.length;
        path.add(pos);
        visit[pos] = true;
      
        if (pos == N-1) {
            //到达终点将结果存入ans
            ans.add(new ArrayList<Integer>(path));
        } else {
            //搜寻下一步所要走的节点
            for (int next : graph[pos]) 
                if (!visit[next]) DFS(next, path, visit);
        }
        //从当前节点离开
        path.remove(path.size()-1);
        visit[pos] = false;
    }
}
```
#### 复杂度分析
- 时间复杂度：$O(2^N*N)$ ，其中$2^N$表示最多可能存在的路径数量，除去起点$0$和终点$N-1$，我们余下$N-2$个节点，我们可以在这$N-2$个节点中分别挑选出$1$个，$2$个...$N-2$个节点作为路径中的中间节点。即$(N-2)*C(1,N-2) + (N-2)*C(2,N-2) + ... + (N-2) * C(N-2,N-2)$。而对于每条路径DFS算法的时间复杂度为$O(N)$。
- 空间复杂度：$O(2^N*N)$
