```
public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        return allPathsSourceTarget(graph, 0);
    }

    /**
     * 实际处理
     *
     * @param graph 图
     * @param n     当前是第几个节点
     * @return 路径
     */
    private List<List<Integer>> allPathsSourceTarget(int[][] graph, int n) {
        List<List<Integer>> lists = new ArrayList<>();
        // 如果当前是最后一个节点，则直接返回一条路径，路径只有当前节点
        if (n == graph.length - 1) {
            List<Integer> path = new ArrayList<>();
            path.add(graph.length - 1);
            lists.add(path);
            return lists;
        }
        // 遍历该节点可以通往其他节点的路，将当前节点添加在路径最前
        for (int i : graph[n]) {
            for (List<Integer> path : allPathsSourceTarget(graph, i)) {
                path.add(0, n);
                lists.add(path);
            }
        }
        return lists;
    }

```
