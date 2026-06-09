### 解题思路
此处撰写解题思路

### 代码

```java
//拓扑排序：BFS+入度：每次使用“剔除边缘结点”的策略，这里的边缘结点就是指连接其它结点最少的结点，用专业的名词来说，就是指向它的结点最少的结点，“入度”最少的结点。//结点最后只会剩下 1 个或者 2 个。
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        //1 边界值处理
        if (n <= 2) {
            for (int i=0; i<n; i++) {
                res.add(i);
            }
            return res;
        }
        //2 入度数组并初始化
        int[] indegree = new int[n];
        // 保存每个数和他相邻得数
        Map<Integer, ArrayList<Integer>> map = new HashMap<>();
        for (int i=0; i<n; i++) {
            map.put(i, new ArrayList<>());
        }
        for (int[] edge : edges) {
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            map.get(edge[0]).add(edge[1]);
            map.get(edge[1]).add(edge[0]);
        }
        //3 bfs广度优先遍历，入度为1的先入队列
        LinkedList<Integer> queue = new LinkedList<>();
        for (int i=0; i < n; i++) {
            if (indegree[i] == 1) {
                queue.offer(i);
            }
        }
        //4 将队列中入度为1的数出列，并更新其相邻节点的入度数
        while (!queue.isEmpty()) {
            //这里每次清空res，直到最后保存最后的结果
            res = new ArrayList<>();
            int size = queue.size();
            for (int i=0; i<size; i++) {
                int cur = queue.poll();
                res.add(cur);
                List<Integer> nexts = map.get(cur);
                for(Integer next : nexts) {
                    indegree[next]--;
                    if (indegree[next] == 1) {
                        queue.offer(next);
                    }
                }
            }
        }
        return res;
    }
}
```