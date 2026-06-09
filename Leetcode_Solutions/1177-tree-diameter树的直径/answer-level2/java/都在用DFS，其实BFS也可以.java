用BFS，，每次取出度为1的节点，并把层数k加一。若最后剩一个节点，则最长路径长度为2 * k;
若最后剩两个节点，则最长路径为 2*k+1
```
class Solution {
    public int treeDiameter(int[][] edges) {
        int n = edges.length+1;
        int[] degree = new int[n];
        HashSet<Integer>[] graph = new HashSet[n];
        for (int i=0; i<n; i++)
            graph[i] = new HashSet<Integer>(); 
        for (int[] edge: edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        Queue<Integer> q = new LinkedList<>();
        int k = 0, left = n;
        for (int i=0; i<n; i++)
            if (degree[i] == 1) q.offer(i);
        while (!q.isEmpty()) {
            if (left <= 2) break;
            int size = q.size();
            for (int i=0; i<size; i++) {
                int node = q.poll();
                degree[node]--;
                for (int nei: graph[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1)
                        q.offer(nei);
                }
            }
            left -= size;
            k++;
        }
        return left == 2 ? 2*k+1 : 2*k;
    }
}
```