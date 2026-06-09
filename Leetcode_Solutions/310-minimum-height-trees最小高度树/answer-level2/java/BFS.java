### 解题思路
由最外层向最内层遍历，保留好每一层的结果，挺有启发的一道题，然而我超时了哈哈哈

### 代码

```java
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if (n == 1){
            res.add(0);
            return res;
        }
        List<Integer>[] graph = new List[n];
        for(int i = 0;i < n ; i++)
            graph[i] = new ArrayList<>();
        int[] degree = new int[n];
        for (int[] edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < degree.length; i++) {
            if (degree[i] == 1){
                queue.offer(i);
            }
        }
        List<Integer> ans = null;
        while (!queue.isEmpty()){
            ans = new ArrayList<>();
            int len = queue.size();
            while (len-- != 0){
                Integer temp = queue.poll();
                ans.add(temp);
                List<Integer> neighbors = graph[temp];
                for (Integer neighbor : neighbors) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1){
                        queue.offer(neighbor);
                    }
                }
            }
        }
        return ans;
    }
}
```