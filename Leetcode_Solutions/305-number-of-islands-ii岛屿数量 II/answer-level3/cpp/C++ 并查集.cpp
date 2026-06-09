每次添加新的大陆，都检查其邻居是否已经是大陆，如果已经是大陆了，比较与自身大陆归属的岛屿是否相同
代码如下：
```
class Solution {
public:
    vector<int> F;
    int father(int x) {
        if (x != F[x]) F[x] = father(F[x]);
        return F[x];
    }
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        F.resize(m * n);
        for (int i = 0; i < m * n; ++i) F[i] = i;
        vector<vector<int> > graph(m, vector<int>(n, 0));
        vector<int> res;
        for (auto& pos : positions) {
            int r = pos[0];
            int c = pos[1];
            int num = ((res.empty()) ? 0 : res.back());
            if (graph[r][c] == 1) {
                res.push_back(num);
                continue;
            }
            ++num;
            graph[r][c] = 1;
            int ind = r * n + c;
            int f1 = father(ind);
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || graph[nr][nc] == 0) continue;
                int nind = nr * n + nc;
                int f2 = father(nind);
                if (f1 != f2) {
                    --num;
                    F[f1] = f2;
                    f1 = f2;
                }
            }
            res.push_back(num);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/1f27f2c866245171019a5e1c7633352b6ef82d8a64557a2c7db185e346d84d39-image.png)
