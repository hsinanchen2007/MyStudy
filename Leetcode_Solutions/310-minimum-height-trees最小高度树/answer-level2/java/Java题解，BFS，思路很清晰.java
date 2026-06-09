#### 这一题我最开始的思路超时了（最后两个数据点没有过= =！），主要想法就是用邻接表存结点信息，然后循环每个结点，计算每个结点的高度，最后再来一次循环，将高度等于最低高度的结点插入到要返回的结果数组，但是这种解法比较暴力，所以时间复杂度就很高，导致超时，后来借鉴了各位老哥的想法，发现还是挺巧妙的，学习了。
#### 解题思路：既然要求最小高度，那么从我们直觉来看，结点肯定是在最内部的，因为题目说了是无向图，所以越靠近边缘，高度肯定就会越大。然后找几组数据，自己手动模拟一下，发现，最终的结点就是位于最中间的1个或2个结点。
- 首先对于数据进行初始化，这里使用degree数组来描述当前结点的度（因为我们每次都是要从边缘进行逐层的删除，而边缘就是度为1的结点），并且使用邻接表来存储和当前结点相邻的结点。
- 将度为1的结点（边缘结点）插入到队列中，我们这里使用一个数组minHeightTreeToot来存每一层的结点，那么最后一次插入的所有结点就一定是最后一层的结点（也就是我们需要的最内部层的结点），这句话有点绕，仔细体会一下。
- 返回minHeightTreeToot数组即可。
#### 完整的代码
```
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer>minHeightTreeToot = new ArrayList<>();
        if (n == 1) {
            minHeightTreeToot.add(0);
            return minHeightTreeToot;
        }
        int first,second;
        int[] degree = new int[n];
        List<List<Integer>>adjacencyList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int[] cur : edges) {
            first = cur[0];
            second = cur[1];
            degree[first]++;
            degree[second]++;
            adjacencyList.get(first).add(second);
            adjacencyList.get(second).add(first);
        }
        Queue<Integer>queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                queue.add(i);
            }
        }
        List<Integer>nextNode;
        int size, curNode;
        while (!queue.isEmpty()) {
            size = queue.size();
            minHeightTreeToot.clear();
            for (int j = 0; j < size; j++) {
                curNode = queue.poll();
                minHeightTreeToot.add(curNode);
                nextNode = adjacencyList.get(curNode);
                for (int node : nextNode) {
                    degree[node]--;
                    if (degree[node] == 1) {
                        queue.add(node);
                    }
                }
            }
        }
        return minHeightTreeToot;
    }
}
```
