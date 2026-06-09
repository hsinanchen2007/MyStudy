```
class Solution {
    public int findCircleNum(int[][] M) {
        int cnt = 0;
        UF uf = new UF(M.length);
        for (int i = 0; i < M.length; ++i) {
            for (int j = 0; j < M[0].length; ++j) {
                if (M[i][j] == 1)
                    uf.union(i, j);
            }
        }
        return uf.connections();
    }
}
class UF {
    private int cnt;
    private int size[];
    private int uf[];

    UF(int N) {
        uf = new int[N];
        size = new int[N];
        cnt = N;
        for (int i = 0; i < N; ++i) {
            uf[i] = i;
            size[i] = 1;
        }
    }

    public void union(int v, int w) {
        int rootLeft = find(v);
        int rootRight = find(w);
        if (rootLeft == rootRight) return;
        if (size[rootRight] > size[rootLeft]) {
            uf[rootLeft] = rootRight;
            size[rootRight] += size[rootLeft];
        } else {
            uf[rootRight] = rootLeft;
            size[rootLeft] += size[rootRight];
        }
        --cnt;
    }

    private int find(int v) {
        int r = v;
        while (r != uf[r]) r = uf[r];
        while (v != r) {
            int tmp = uf[v];
            uf[v] = r;
            v = tmp;
        }
        return r;
    }

    public boolean connected(int v, int w) {return find(v) == find(w);}

    public int connections() {return cnt;}

}
```