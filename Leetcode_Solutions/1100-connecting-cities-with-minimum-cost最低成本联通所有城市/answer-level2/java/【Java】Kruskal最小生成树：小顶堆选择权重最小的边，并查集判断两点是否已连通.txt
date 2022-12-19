每次选择具有最小权重，且两顶点还未连通的边。
不多解释，直接看代码
```
class Solution {
    
    public int minimumCost(int N, int[][] conections) {
        int edgeNum = conections.length;
        
        Comparator<Edge> comparator = new Comparator<Edge>() {
            public int compare(Edge e1, Edge e2) {
                return e1.cost - e2.cost;
            }
        };
        PriorityQueue<Edge> edgeHeap = new PriorityQueue<Edge>(edgeNum, comparator);
        for (int i = 0; i < edgeNum; ++i)
            edgeHeap.offer(new Edge(conections[i]));
        
        UnionFind uf = new UnionFind(N);
        int total = 0;
        Edge edge;
        while (edgeHeap.peek() != null) {
            edge = edgeHeap.poll();
            if (uf.connected(edge.p1, edge.p2))
                continue;
            total += edge.cost;
            uf.union(edge.p1, edge.p2);
        }
                
        return uf.allTogether() ? total : -1;
    }
}

class UnionFind {
    public int[] roots;
    
    public UnionFind(int N) {
        roots = new int[N+1];
        for (int i = 1; i <= N; ++i)
            roots[i] = i;
    }
    
    public int findRoot(int i) {
        int root = i;
        while (root != roots[root])
            root = roots[root];
        int parent;
        while (i != roots[i]) {
            parent = roots[i];
            roots[i] = root;
            i = parent;
        }
        return root;
    }
    
    public boolean connected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }
    
    public void union(int p, int q) {
        int pRoot = findRoot(p);
        int qRoot = findRoot(q);
        roots[pRoot] = qRoot;
    }
    
    public boolean allTogether() {
        int root1 = findRoot(1);
        for (int i = 2; i < roots.length; ++i) {
            if (root1 != findRoot(i))
                return false;
        }
        return true;
    }
}

class Edge {
    
    public int p1;
    public int p2;
    public int cost;
    
    public Edge(int[] triple) {
        p1 = triple[0];
        p2 = triple[1];
        cost = triple[2];
    }
}
```


![image.png](https://pic.leetcode-cn.com/80bc1e7f853bdbaf251970d1751f3d6eb163879662fe96385af1db92aae95ec8-image.png)
