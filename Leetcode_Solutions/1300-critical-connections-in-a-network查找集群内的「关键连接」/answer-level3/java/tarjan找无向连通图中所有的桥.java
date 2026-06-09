### 解题思路
![屏幕快照 2020-01-31 下午5.02.58.png](https://pic.leetcode-cn.com/d1bcee68f11eb5c7067793fe6895746e6715f0e9106d3db6b78a3ba1ed7bf01e-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-31%20%E4%B8%8B%E5%8D%885.02.58.png)

tarjan算法找无向联通图中的桥。模版题，直接套模版。


### 代码

```java
class Solution {
    public Edge[] edges;
    public int cnt;
    public int[] fir;
    static class Edge {
        int u,v,w,next;
        boolean cut;
        int num;
    }

    int[] low;
    int[] dfn;
    int recdfn;
    void tarjanAddEdge(int u, int v, int w) {
        edges[cnt] = new Edge();
        edges[cnt].u = u;
        edges[cnt].v = v;
        edges[cnt].w = w;
        edges[cnt].cut = false;
        edges[cnt].num = 0;
        edges[cnt].next = fir[u];
        fir[u] = cnt++;
    }
    public void initTarjan(int nodeSize, int edgeSize) {
        cnt = 0;
        edges = new Edge[edgeSize + 10];
        low = new int[nodeSize + 10];
        dfn = new int[nodeSize + 10];
        fir = new int[edgeSize + 10];
        Arrays.fill(fir, -1);
    }

    public void tarjan(int u, int fa) {
        low[u] = dfn[u] = ++recdfn;
        int have  = 0;
        for(int i = fir[u]; i != -1; i = edges[i].next) {
            int v = edges[i].v;
            if(have == 0 && v == fa) {
                //走过你来时的路
                have++;
                continue;
            }
            if(dfn[v] == 0) {
                //dfs过程中还未经过该点
                this.tarjan(v, u);
                low[u] = Math.min(low[u], low[v]);
                if(low[v] > dfn[u]) {
                    edges[i].cut = true;
                    edges[i^1].cut = true;
                }
            } else {
                //取已访问的节点的dfs序的最小值
                low[u] = Math.min(low[u], dfn[v]);
            }
        }
    }
    public boolean findEdgeCut(int l, int r) {
        Arrays.fill(low, 0);
        Arrays.fill(dfn, 0);
        recdfn = 0;
        tarjan(l, l);
        for(int i = l; i <= r; i++) {
            if(dfn[i] == 0) {
                return Boolean.FALSE;
            }
        }
        return Boolean.TRUE;
    }

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        this.initTarjan(n, connections.size() * 2);
        for (List<Integer> edge : connections) {
            tarjanAddEdge(edge.get(0), edge.get(1), 1);
            tarjanAddEdge(edge.get(1), edge.get(0), 1);
        }
        boolean ans = findEdgeCut(0, n - 1);
        List<List<Integer>> result = new ArrayList<>();
        int l = connections.size();
        for (int i = 0; i < l * 2; i += 2) {
            Edge edge = edges[i];
            if (edge != null && edge.cut) {
                List<Integer> t = new ArrayList<>();
                t.add(edge.u);
                t.add(edge.v);
                result.add(t);
            }
        }
        return result;
    }

}
```