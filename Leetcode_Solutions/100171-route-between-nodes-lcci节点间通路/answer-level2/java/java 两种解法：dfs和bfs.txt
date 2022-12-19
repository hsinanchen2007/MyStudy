**思路**
1. 先建立一个邻接表
```java
    List<Integer>[] adj = new ArrayList[n];
    for (int[] edge : graph) {
        int from = edge[0];
        int to = edge[1];
        if (adj[from] == null) {
            adj[from] = new ArrayList<>();
        }

        adj[from].add(to);
    }
```

2. 再使用dfs或bfs来判断start到target是否可达

```java
    private boolean hasPath(int start, int target) {
        // dfs
        if (start == target) {
            return true;
        }

        visited[start] = true;

        List<Integer> nextList = adj[start];
        if (nextList == null) {
            return false;
        }

        for (Integer next: nextList) {
            if (visited[next]) {
                continue;
            }

            if (hasPath(next, target)) {
                return true;
            }
        }

        return false;
    }
``` 

```java
    private boolean hasPath(int n, List<Integer>[] adj, int start, int target) {
        // bfs
        LinkedList<Integer> queue = new LinkedList<>();
        queue.offer(start);
        boolean[] visited = new boolean[n];
        visited[start] = true;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int node = queue.poll();
                List<Integer> nextList = adj[node];
                if (nextList == null) {
                    continue;
                }

                for (Integer next: nextList) {
                    if (next == target) {
                        return true;
                    }

                    if (visited[next]) {
                        continue;
                    }

                    visited[next] = true;
                    queue.add(next);
                }
            }
        }

        return false;
    }

```