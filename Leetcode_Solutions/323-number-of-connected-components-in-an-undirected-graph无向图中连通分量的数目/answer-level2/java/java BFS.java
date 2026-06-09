```java

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int countComponents(int n, int[][] edges) {
        // 构造邻接表，考虑是无向边
        List<Integer> E[] = new ArrayList[n];
        boolean F[] = new boolean[n];
        for (int[] e : edges) {
            if (E[e[0]] == null) E[e[0]] = new ArrayList();
            if (E[e[1]] == null) E[e[1]] = new ArrayList();
            E[e[0]].add(e[1]);
            E[e[1]].add(e[0]);
        }
        int isSimNet = 0;
        Queue<Integer> Q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (F[i]) {//当前要BFS的起始节点在前面已经被访问，它属于某个连通子图
                ++isSimNet;
                continue;
            }
            if (E[i] == null || E[i].size() < 1) continue;
            //将节点i的所有直接或间接关联的节点遍历
            Q.add(i);
            while (!Q.isEmpty()) {
                int start = Q.remove();
                F[start] = true;
                for (int e : E[start]) {
                    if (F[e]) continue;
                    Q.add(e);
                    F[e] = true;
                }
            }

        }
        return n - isSimNet;
    }

    public static void main(String[] args) {
        int n = 5;
        int[][] map = new int[][]{{0, 1}, {1, 2}, {3, 4}};
        int c = new Solution().countComponents(n, map);
        System.out.println(c);
    }
}
```