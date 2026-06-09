### 解题思路
1. BFS遍历图, 如果连通分量为1则说明是树
2. 并查集

### 代码

**BFS**
```java []
class Solution {
    public boolean validTree(int n, int[][] edges) {
        // bfs
        if(edges == null || edges.length==0 || edges[0].length==0)
            return n==1;
        if(edges.length != n-1)
            return false;

        HashMap<Integer, HashSet<Integer>> graph = makeGraph(n, edges);
        Queue<Integer> q = new LinkedList<Integer>();
        HashSet<Integer> rec = new HashSet<>();

        // bfs检测图中的连通分量的数量
        q.offer(0);
        rec.add(0);
        while(!q.isEmpty()){
            int node = q. poll();
            for(int adjNode: graph.get(node)){
                if(!rec.contains(adjNode)){
                    q.offer(adjNode);
                    rec.add(adjNode);
                }
            }
        }

        return rec.size()==n;
        
    }

    private HashMap<Integer, HashSet<Integer>> makeGraph(int n, int [][]edges){
        HashMap<Integer, HashSet<Integer>> graph = new HashMap<>(); 
        for(int i=0; i<n; ++i){
            graph.put(i, new HashSet());
        }

        for(int []edge: edges){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        return graph;
    }
}
```
```python []
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # bfs
        if edges==None or len(edges)==0 or edges[0]==None or len(edges[0])==0:
            return n==1
        if len(edges) != n-1:
            return False

        q = [0]
        rec = set([0])

        graph = self.makeGraph(n, edges)

        while len(q) > 0:
            node = q.pop(-1)
            for adjNode in graph[node]:
                if adjNode not in rec:
                    rec.add(adjNode)
                    q.append(adjNode)

        return len(rec)==n

    def makeGraph(self, n, edges):
        graph = dict()
        for i in range(n):
            graph[i] = set()

        for edge in edges:
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])

        return graph
```
```c++ []
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 树判定的依据
        // 1. n个节点和n-1条边
        // 2. bfs遍历, 所有经过的顶点数量=n, 且图中不存在环

        if(n == 0)
            return false;

        if(edges.size() != n-1)
            return false;

        map<int, set<int>> graph = makeGraph(n, edges);

        // bfs 访问图的辅助队列
        queue<int> q;
        // 记录访问的节点
        unordered_set<int> rec;
        // 添加初始顶点
        q.push(0);
        rec.insert(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adjNode: graph[node]){
                if(rec.find(adjNode) != rec.end())
                    continue;
                rec.insert(adjNode);
                q.push(adjNode);
            }
        }

        return rec.size() == n;
    }

private:
    map<int, set<int>> makeGraph(int n, const vector<vector<int>>& edges){
        map<int, set<int>> graph;
        for(auto &vec : edges){
            graph[vec[0]].insert(vec[1]);
            graph[vec[1]].insert(vec[0]);
        }

        return graph;
    }
};
```

**并查集**

```java []
class Solution {
    private class UnionFind{
        public UnionFind(int n){
            this.parent = new int[n];
            Arrays.fill(parent, -1);

            this.rank = new int[n];
            Arrays.fill(rank, 0);

            this.sc = n;
        }

        private int find(int v){
            while(parent[v] != -1){
                v = parent[v];
            }
            return v;
        }

        public boolean union(int x, int y){
            int Px = find(x);
            int Py = find(y);
            // x和y形成了loop
            if(Px == Py)
                return false;

            // 路径压缩
            if(rank[Px] < rank[Py])
                parent[Px] = Py;
            else if(rank[Px] > rank[Py])
                parent[Px] = Py;
            else{
                parent[Px] = Py;
                rank[Py]++;
            }
            
            sc--;
            return true;

        }

        public int getSc(){
            return sc;
        }

        private int []parent;
        private int []rank;
        private int sc;
    }

    public boolean validTree(int n, int[][] edges) {
        // 使用Union-Find判断
        UnionFind uf = new UnionFind(n);
        for(int[] edge: edges){
            if(!uf.union(edge[0], edge[1]))
                return false;
        }
        return uf.getSc()==1;

    }
}
```
```python []
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # 并查集
        uf = UnionFind(n)
        for edge in edges:
            if uf.union(edge[0], edge[1]) is False:
                return False

        return uf.getSc()==1


# 并查集类
class UnionFind:
    def __init__(self, n):
        self.parent = [-1 for _ in range(n)]
        self.rank = [0 for _ in range(n)]
        self.sc = n

    def find(self, v):
        while self.parent[v] != -1:
            v = self.parent[v]
        return v

    def union(self, x, y):
        print('x={} and y={}'.format(x, y))
        Px, Py = self.find(x), self.find(y)
        print('Px={} and Py={}'.format(Px, Py))
        # 如果两个点属于同一个集合
        if Px == Py:
            return False
        
        # 基于rank的路径压缩
        if self.rank[Px] < self.rank[Py]:
            Py = self.parent[Px]

        elif self.rank[Px] > self.rank[Py]:
            Px = self.parent[Py]

        else:
            Px = self.parent[Py]
            self.rank[Px]+=1

        self.sc-=1
        return True


    def getSc(self):
        return self.sc
```
```c++ []
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 并查集
        UnionFind *uf = new UnionFind(n);
        for(auto& vec: edges){
            // 环检测
            if(!uf->uni(vec[0], vec[1]))
                return false;
        }
        // 连通分量检测
        return uf->getSc()==1;
    }

private:
    class UnionFind{
    private:
        int n;
        vector<int> parent;
        vector<int> rank;
        // 连通分量
        int cnt;
    public:
        UnionFind(int n){
            this->n = n;
            this->parent = vector<int>(n, -1);
            this->rank = vector<int>(n, 0);
            // 初始连通分量设置为n
            this->cnt = n;
        }

    private:
        int find(int v){
            while(parent[v] != -1)
                v = parent[v];
            return v;
        }

    public:
        bool uni(int x, int y){
            int Px = find(x);
            int Py = find(y);
            if(Px == Py)
                return false;

            // 根据rank进行路径压缩
            if(rank[Px] > rank[Py])
                parent[Py] = Px;
            else if(rank[Px] < rank[Py])
                parent[Px] = Py;
            else{
                parent[Py] = Px;
                rank[Px]++;
            }
            cnt--;
            return true;
        }

        int getSc(){
            return this->cnt;
        }
    };
};
```
