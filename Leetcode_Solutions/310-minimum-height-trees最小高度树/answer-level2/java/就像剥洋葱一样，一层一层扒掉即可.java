### 解题思路
剥洋葱算法，具体都在代码注释中，请自己看

### 代码

```java
class Solution {
/**
     * 解题思路：既然要求最小高度，那结点肯定是在最内部的，因为题目说了是无向图，
     * 所以越靠近边缘，高度肯定就会越大。(这是自然的，越靠近1边，这边越短，另外一边就越长——无向图是双向的)
     *
     * 所有把外围叶子节点通通一层一层剥掉，剥干净之后，剩下的1-2个节点就是我们要找的树根，树根只可能1-2个
     * @param n
     * @param edges
     * @return
     */    
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> minHeightTreeNode = new ArrayList<>();
        // 如果n=1，只给定了1，那就返回最小树的根节点0
        if (n == 1) {
            minHeightTreeNode.add(0);
            return minHeightTreeNode;
        }

        // 这是定义每个边的数组元素的第0个值和第1个值
        int element0,element1;
        // 这是所有节点的入度列表（被指向的次数）
        int[] inDegree = new int[n];

        // 这是每个节点的邻接列表，比如 0-1,2,3,
        //                          1-0,xx,xx...
        List<List<Integer>>adjacencyList = new ArrayList<>();

        // 初始化邻接列表
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int[] cur : edges) {
            element0 = cur[0];
            element1 = cur[1];
            inDegree[element0]++;
            inDegree[element1]++;
            // 邻接列表要初始化两边（不同方向），因为是无向图，所以方向是双向的
            adjacencyList.get(element0).add(element1);
            adjacencyList.get(element1).add(element0);
        }

        // 这个是测试边不为0的容器
        // 用stack也是可以的
        // 首先把入度为1的元素（叶子节点）放入
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) {
                queue.add(i);
            }
        }

        // 当前节点的临近列表
        List<Integer> curNodeAdjacentList;
        int size, curNode;
        // 像剥洋葱一样层层把叶子节点去掉
        // 去掉一圈叶子节点，剩下的又变成了叶子节点
        // 叶子节点就是入度为0的节点
        while (!queue.isEmpty()) {
            // 需要记住当前queue的剩余大小
            // 每次都整整清除一圈
            size = queue.size();
            minHeightTreeNode.clear();
            for (int j = 0; j < size; j++) {
                curNode = queue.poll();
                minHeightTreeNode.add(curNode);
                curNodeAdjacentList = adjacencyList.get(curNode);
                for (int node : curNodeAdjacentList) {
                    // 把当前节点对应的邻接列表的入度都减1
                    inDegree[node]--;
                    // 如果被减1的邻接列表的节点就剩下1了，那就证明它就是叶子节点了
                    if (inDegree[node] == 1) {
                        queue.add(node);
                    }
                }
            }
        }
        return minHeightTreeNode;
    }
}
```