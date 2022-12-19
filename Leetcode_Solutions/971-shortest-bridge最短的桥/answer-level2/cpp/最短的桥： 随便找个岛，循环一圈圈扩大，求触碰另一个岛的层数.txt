
主逻辑：
```cpp
// class ShortestBridge: public MyDebug {
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int level = 0;
        vector<POINT> edges;
        // 找到一个岛，并mark所有状态从M_ISLAND到M_MARKED，并获取所有edges点。
        InitEdges(A, edges);
        // PrintVector2(A,"Inited");
        // 循环扩大一圈, 新的一圈置为M_MARKED，碰到M_ISLAND（标示触碰另外一岛屿），返回失败。否则扩大成功， level++
        while(EnlargeEdges(A, edges) > 0) {
            level++;
            // PrintVector2(A,"one loop");
        }
        return level;
    }
};
```

辅助函数
```cpp
struct POINT {
    int r;
    int c;
    POINT(int rIn, int cIn) : r(rIn), c(cIn) {};
};

static const POINT DIR[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// class ShortestBridge: public MyDebug {
class Solution {
public:
    int EnlargeEdges(vector<vector<int>>& A, vector<POINT> &edges) {
        vector<POINT> edgesRet;
        POINT size(A.size(), A[0].size());
        vector<vector<char>> visited(size.r, vector<char>(size.c, 0));
        for (auto cur: edges) {
            int isEdge = 0;
            for (int next = 0; next < sizeof(DIR) / sizeof(DIR[0]); next++) {
                POINT n(cur.r + DIR[next].r, cur.c + DIR[next].c);
                if (n.r < 0 || n.r >= size.r || n.c < 0 || n.c >= size.c) { continue; }
                if (visited[n.r][n.c] == 1) { continue; }
                visited[n.r][n.c] = 1;
                if (A[n.r][n.c] == M_ISLAND) { return -1;}
                if (A[n.r][n.c] == M_MARKED) { continue; }
                edgesRet.push_back(n);
                A[n.r][n.c] =  M_MARKED;
            }
        }
        edges.swap(edgesRet);
        return 1;
    }

    void InitEdges(vector<vector<int>>& A, vector<POINT> &edges) {
        queue<POINT> q;
        POINT size(A.size(), A[0].size());
        POINT cur = GetFirstPoint(A, M_ISLAND);
        vector<vector<char>> visited(size.r, vector<char>(size.c, 0));
        q.push(cur);
        visited[cur.r][cur.c] = 1;
        while (!q.empty()) {
            int isEdge = 0;
            cur = q.front(); q.pop();
            A[cur.r][cur.c] =  M_MARKED;
            for (int next = 0; next < sizeof(DIR) / sizeof(DIR[0]); next++) {
                POINT n(cur.r + DIR[next].r, cur.c + DIR[next].c);
                if (n.r < 0 || n.r >= size.r || n.c < 0 || n.c >= size.c) { continue; }
                if (visited[n.r][n.c] == 1) { continue; }
                visited[n.r][n.c] = 1;
                if (A[n.r][n.c] == M_WATER) { isEdge++;}
                else { q.push(n); }
            }
            if (isEdge > 0) { edges.push_back(cur); }
        }
    }

    POINT GetFirstPoint(vector<vector<int>>& A, int mark) {
        for (int r = 0; r < A.size(); r++) {
            for (int c = 0; c < A[r].size(); c++) {
                if (A[r][c] == mark) {return POINT(r,c);}
            }
        }
        return POINT(-1, -1);
    }
};
```
