```
class Solution {
    int fa[] = new int[100001];

    int father(int x) {
        if (fa[x]!=x) {
            fa[x]=father(fa[x]);
        }
        return fa[x];
    }

    void create(int a, int b) {
        int fa1 = father(a);
        int fa2 = father(b);
        if (fa1 != fa2) {
            fa[fa2] = fa1;
        }
    }
    

    public int makeConnected(int n, int[][] connections) {
        if(n - connections.length > 1)
            return -1;
        for (int i = 0; i<n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i<connections.length; i++) {
            create(connections[i][0], connections[i][1]);
        }
        int[] visit = new int[n];
        for (int i = 0; i<n; i++) {
            visit[father(i)] = 1;
        }
        int re = 0;
        for (int i = 0; i<n; i++) {
            if (visit[i] == 1) {
                re++;
            }
        }
        return re-1;
    }
}
```
