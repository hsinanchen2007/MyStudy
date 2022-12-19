需要进行路径的排序，否则会超时
1.DFS
```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, Integer> distance = new HashMap<>(); // 记录到达当前节点的最短路径
        Map<Integer, List<int[]>> graph = new HashMap<>(); // 使用map构造邻接表
        for (int[] item : times) {
            if (!graph.containsKey(item[0])) {
                graph.put(item[0], new ArrayList<>());
            }
            graph.get(item[0]).add(new int[] {item[1], item[2]});
        }

        for (int node : graph.keySet()) {
            Collections.sort(graph.get(node), new Comparator<int[]>() {
                public int compare(int[] a, int[] b) {
                    return a[1] - b[1];
                }
            });
        }
        for (int i = 1; i <= N; i++) {
            distance.put(i, Integer.MAX_VALUE);
        }
        dfs(graph, distance, K, 0);
        int ans = -1;
        for (int dis : distance.values()) {
            // System.out.println(dis);
            if (dis == Integer.MAX_VALUE) {
                return -1;
            }
            ans = Math.max(ans, dis);
        }
        return ans;
    }

    public void dfs(Map<Integer, List<int[]>> graph, Map<Integer, Integer> distance, int K, int dis) {
        if (dis >= distance.get(K)) { // 一定要 >=
            return;
        }
        distance.put(K, dis);
        if (graph.containsKey(K)) {
            for (int[] list : graph.get(K)) {
                dfs(graph, distance, list[0], dis + list[1]);
            }
        }
    }
}
```
2.BFS
```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, Integer> distance = new HashMap<>(); // 记录到达当前节点的最短路径
        Map<Integer, List<int[]>> graph = new HashMap<>(); // 使用map构造邻接表
        for (int[] item : times) {
            if (!graph.containsKey(item[0])) {
                graph.put(item[0], new ArrayList<>());
            }
            graph.get(item[0]).add(new int[] {item[1], item[2]});
        }

        for (int node : graph.keySet()) {
            Collections.sort(graph.get(node), new Comparator<int[]>() {
                public int compare(int[] a, int[] b) {
                    return a[1] - b[1];
                }
            });
        }
        for (int i = 1; i <= N; i++) {
            distance.put(i, Integer.MAX_VALUE);
        }
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(K, 0));
        while (!queue.isEmpty()) {
            Node top = queue.poll();
            if (top.dis >= distance.get(top.K)) { // >=
                continue;
            }
            distance.put(top.K, top.dis);
            if (graph.containsKey(top.K)) {
                for (int[] item : graph.get(top.K)) {
                    queue.offer(new Node(item[0], item[1] +top.dis));
                }
            }
        }
        int ans = -1;
        for (int dis : distance.values()) {
            // System.out.println(dis);
            if (dis == Integer.MAX_VALUE) {
                return -1;
            }
            ans = Math.max(ans, dis);
        }
        return ans;
    }

    static class Node {
        int K;
        int dis;
        public Node(int K, int dis) {
            this.K = K;
            this.dis = dis;
        }
    }
}
```
3.Dijkstra(堆)
```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, List<int[]>> graph = new HashMap();
        for (int[] edge: times) {
            if (!graph.containsKey(edge[0]))
                graph.put(edge[0], new ArrayList<int[]>());
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
        }
        Map<Integer, Integer> dist = new HashMap();
        PriorityQueue<Node> heap = new PriorityQueue<Node>(new Comparator<Node>() {
            public int compare(Node n1, Node n2) {
                return n1.dis - n2.dis;
            }
        });
        heap.offer(new Node(K, 0));
        while (!heap.isEmpty()) {
            Node top = heap.poll();
            int node = top.K;
            int dis = top.dis;
            if (dist.containsKey(node)) {
                continue;
            }
            dist.put(node, dis);
            if (graph.containsKey(node)) {
                for (int[] item : graph.get(node)) {
                    if (!dist.containsKey(item[0])) {
                        heap.offer(new Node(item[0], dis + item[1]));
                    }
                }
            }
        }
        if (dist.size() != N) return -1;
        int ans = 0;
        for (int cand: dist.values())
            ans = Math.max(ans, cand);
        return ans;
    }

    class Node {
        int K;
        int dis;
        Node(int K, int dis) {
            this.K = K;
            this.dis = dis;
        }
    }
}
```


