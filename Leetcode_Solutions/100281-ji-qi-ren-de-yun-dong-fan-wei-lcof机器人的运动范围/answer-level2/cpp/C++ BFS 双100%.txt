C++ 宽搜 双100%
`执行用时：0 ms
内存消耗：6.1 MB`
```cpp
class Solution {
private:
    int mat[100][100]={};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    int BFS(int m, int n, int k){
        queue<pair<int, int> > q;
        pair<int,int> cur;
        int xx, yy, x, y;
        q.push(make_pair(0,0));
        int res = 1;
        mat[0][0] = 1;
        while(!q.empty()){
            cur = q.front();
            x = cur.first;y = cur.second;
            q.pop();
            for (int i = 0; i < 4; ++i){
                xx = dx[i] + x;
                if (xx < 0 || xx >= m) continue; //边界约束
                yy = dy[i] + y;
                if (yy < 0 || yy >= n) continue; //边界约束
                if (mat[xx][yy] == 0                              //约束已访问过
                && (xx / 10 + xx % 10 + yy / 10 + yy % 10) <= k){ //约束k
                    mat[xx][yy] = 1;
                    ++res;
                    q.push(make_pair(xx, yy));
                }
            }
        }
        return  res;
    }
    int movingCount(int m, int n, int k) {
        return BFS(m, n, k);
    }
};
```
