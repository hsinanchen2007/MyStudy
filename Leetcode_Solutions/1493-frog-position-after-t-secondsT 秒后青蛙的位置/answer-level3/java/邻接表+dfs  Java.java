解题思路：
直接对树进行深度搜索遍历dfs，因为从父节点到各个子节的概率相同，所以到子节点的概率为：
当前节点概率/子节点数目
其中当前节点概率指的是从根节点到当前节点的概率。
如果能在t步内遍历到目标节点，则返回当前概率，否则返回0

create by chris https://github.com/noyo/Leetcode-Hard-Java
```
public class Problem5355 {

    //邻接表
    List<Integer> edges[];
    double res = 0;

    public void dfs(int root, int T, int from, int target, double cur) {
        //节点root能到达的节点列表，包括父节点
        List<Integer> es = edges[root];
        //T < 0 说明时间已用完
        if (T < 0) {
            if (root == target) {
                res = cur;
            }
            return;
        }
        //判断是否无路可走
        boolean move = false;
        for (int i = 0; i < es.size(); i++) {
            int to = es.get(i);
            if (to == from) {
                continue;
            }
            //子节点数
            int cnt = es.size() - (from == -1 ? 0 : 1);
            dfs(to, T - 1, root, target, cur * (1.0 / cnt));
            move = true;
        }
        if (!move && root == target) {
            res = cur;
        }
    }

    public double frogPosition(int n, int[][] g, int t, int target) {
        edges = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            edges[i] = new ArrayList<>();
        }
        //初始化邻接表
        for (int i = 0; i < n - 1; i++) {
            edges[g[i][0]].add(g[i][1]);
            edges[g[i][1]].add(g[i][0]);
        }
        if (t > 0) {
            //初始概率为1.0
            dfs(1, t - 1, -1, target, 1.0);
        } else {
            return target == 1 ? 1 : 0;
        }
        return res;
    }
}
```
