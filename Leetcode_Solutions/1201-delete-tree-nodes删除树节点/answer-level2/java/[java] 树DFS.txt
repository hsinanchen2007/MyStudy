考试时没看到子树,以为任何几个相连的节点满足条件就ok...
代码有详解
![image.png](https://pic.leetcode-cn.com/57ce23d2403c0ec2190b971526700e16562c8fd0ec6b60769a2eacc397713760-image.png)
```
    List<Set<Integer>> childs;
    int[] value;

    public int deleteTreeNodes(int nodes, int[] parent, int[] value) {
        this.value = value;
        childs = new ArrayList<>(nodes);
        for (int i = 0; i < nodes; i++) {
            childs.add(new HashSet<>());
        }

        /**
         * 转换为孩子表示法
         */
        for (int i = 1; i < nodes; i++) {
            childs.get(parent[i]).add(i);
        }

        /**
         * 整棵树和为0,直接返回0
         */
        if (DFS(0) == 0) {
            return 0;
        }

        /**
         * 广度遍历所有存在的节点
         */
        Queue<Integer> BFS = new LinkedList<>();
        BFS.add(0);
        int res = 0;
        while (!BFS.isEmpty()) {
            int v = BFS.remove();
            for (int n : childs.get(v)) {
                BFS.add(n);
            }
            res++;
        }
        return res;
    }

    private int DFS(int num) {
        int res = value[num];
        List<Integer> delete = new ArrayList<>();
        for (int child : childs.get(num)) {
            int v = DFS(child);
            /**
             * 如果下个节点和为0,直接将下个节点删除,下个节点的孩子节点不用删除,
             * 因为是有向无环图,所以删除父节点,孩子节点就无法被访问
             */
            if (v == 0) {
                delete.add(child);
            }
            res += v;
        }

        for (int i : delete) {
            childs.get(num).remove(i);
        }
        return res;
    }
```
