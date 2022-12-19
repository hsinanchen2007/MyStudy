逻辑很简单：各块陆地找到边缘，循环一层层扩大， 扩大到多少层找不到陆地了，层数就是所谓的曼哈顿距离，或者叫离陆地最短海域。
时间击败99%，内存因为复用原数组，击败100%。其实思路跟《934. 最短的桥》是基本一致的。

```cpp
    int maxDistance(vector<vector<int>>& grid) {
        int level = 0;
        // 找到所有陆地。边缘标记为2，下次判断是否是2，就知道它是不是陆地边缘了。
        if(MarkAllEdge(grid, 2) <= 0) { return -1; }
        // 循环 根据边缘标记n增大一圈，新边缘标记为n+1。，返回值标示有多少水域变成了陆地（新边缘） 
        while(EnlargeEdges(grid, level+2) > 0) { level++; }
        return level;
    }
```


详细代码：
```cpp
static const int DIR_C[4] = { 0, 0, 1, -1};
static const int DIR_R[4] = { 1, -1, 0, 0};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int level = 0;
        if(MarkAllEdge(grid, 2) <= 0) { return -1; }
        while(EnlargeEdges(grid, level+2) > 0) { level++; }
        return level;
    }

    int MarkAllEdge(vector<vector<int>>& A, int mark) {
        int row = A.size(), col = A[0].size(), count = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (A[r][c] == 0) { continue; }
                if (IsEdge(A, row, col, r, c)) { A[r][c] =  mark; count++; }
            }
        }
        return count;
    }

    int EnlargeEdges(vector<vector<int>>& A, int edge) {
        int rr, rc, count = 0;
        int row = A.size(), col = A[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if(A[r][c] != edge) { continue; }
                count += EnlargeEdge(A, row, col, r, c, edge);
            }
        }
        return count;
    }

    static inline int EnlargeEdge(vector<vector<int>>& A, int row, int col, int r, int c, int edge) {
        int rr, rc, count=0;
        for (int next = 0; next < sizeof(DIR_C) / sizeof(DIR_C[0]); next++) {
            rr = r + DIR_R[next], rc = c + DIR_C[next];
            if (rr < 0 || rr >= row || rc < 0 || rc >= col) { continue; }
            if (A[rr][rc] != 0) { continue; }
            A[rr][rc] = edge+1;
            count++;
        }
        return count;
    }

    static inline bool IsEdge(vector<vector<int>>& A, int row, int col, int r, int c) {
        int rr, rc;
        for (int next = 0; next < sizeof(DIR_C) / sizeof(DIR_C[0]); next++) {
            rr = r + DIR_R[next], rc = c + DIR_C[next];
            if (rr < 0 || rr >= row || rc < 0 || rc >= col) { continue; }
            if (A[rr][rc] == 0) { return true;}
        }
        return false;
    }

};
```
