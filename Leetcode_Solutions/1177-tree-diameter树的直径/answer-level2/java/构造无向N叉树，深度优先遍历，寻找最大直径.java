### 解题思路
1.构造无向N叉树，0下标的为root节点
2.从root开始，每个孩子节点进行DFS遍历
3.经过节点的最大路径，是*当前节点的所有孩子节点*直径**前二**之和，同时记录下**从当前节点出发**的最大直径，往父节点递推。

当前节点的所有孩子节点直径**前二**之和，这里用了一个优先队列，其实不用优先队列会快个2ms的样子，不过我为了代码更加万精油一点，用了个优先队列。

执行时间：14ms。

注意：我看到有部分题解添加了一个数组来记录当前节点是否访问过，这里我认为是没有必要的，因为这个图构造出来后是一个**无向树**，**树是不存在环的**，**每个节点有且仅有一次访问**，不会出现重复访问的情况。所以没有必要再消耗一个数组的空间。

### 代码

```java
class Solution {
    private TreeVertex root = new TreeVertex(0);// 无向树的根节点

    private static class TreeVertex{
        int index;// 顶点下标
        List<TreeVertex> child;

        TreeVertex(int index){
            this.index = index;
            this.child = new ArrayList<>();
        }
    }

    public int treeDiameter(int[][] edges) {
        if (edges.length == 0){
            return 0;
        }
        // 节点缓存初始化
        Map<Integer,TreeVertex> treeVertexMap = initVertexCache();
        // 构造无向N叉树
        for (int i = 0; i < edges.length; i++) {
            // 获取父顶点
            TreeVertex vertex = getTreeVertex(treeVertexMap,edges[i][0]);
            // 获取孩子顶点
            TreeVertex childVertex = getTreeVertex(treeVertexMap,edges[i][1]);
            vertex.child.add(childVertex);
        }
        int[] maxDiameter = new int[]{0};
        getMaxDiameter(maxDiameter,root);
        return maxDiameter[0];
    }

    /**
     * 获取树当前节点出发的最大直径
     * @param maxDiameter 最大直径
     * @param vertex 顶点
     * @return 当前节点出发的最大直径
     */
    private int getMaxDiameter(int[] maxDiameter,TreeVertex vertex){
        if (vertex == null){
            return 0;
        }
        int curVertexDiameter = 0;// 从当前节点出发的最长路径
        // 记录当前节点出发的两条最长路径，小顶堆
        Queue<Integer> pq = new PriorityQueue<>(2);
        for (TreeVertex temp : vertex.child){
            int tempDiameter = getMaxDiameter(maxDiameter,temp);
            // 当前节点出发的最长路径
            curVertexDiameter = Math.max(curVertexDiameter,tempDiameter);

            // 全局最长路径，只能取vertex孩子的两条最长路径
            if (pq.size() == 2){
                // 比小顶堆堆顶要大，进入小顶堆
                if (tempDiameter > pq.peek()){
                    pq.poll();
                    pq.offer(tempDiameter);
                }
            }else {
                pq.offer(tempDiameter);
            }
        }

        int sumDiameter = 0;
        while (!pq.isEmpty()){
            sumDiameter += pq.poll();
        }
        // 全局最大直径
        maxDiameter[0] = Math.max(maxDiameter[0],sumDiameter);

        // 当前节点出发的最大直径
        return 1 + curVertexDiameter;// 带上本身
    }

    /**
     * 获取无向树顶点
     * @param treeVertexMap 无向树顶点缓存
     * @param index 顶点下标
     * @return 无向树顶点
     */
    private TreeVertex getTreeVertex(Map<Integer,TreeVertex> treeVertexMap,int index){
        TreeVertex vertex = treeVertexMap.get(index);
        if (vertex == null){
            vertex = new TreeVertex(index);
            treeVertexMap.put(index,vertex);
        }
        return vertex;
    }

    /**
     * 初始化顶点缓存
     * @return 初始化缓存
     */
    private Map<Integer,TreeVertex> initVertexCache(){
        Map<Integer,TreeVertex> treeVertexMap = new HashMap<>();
        treeVertexMap.put(0,root);
        return treeVertexMap;
    }
}
```