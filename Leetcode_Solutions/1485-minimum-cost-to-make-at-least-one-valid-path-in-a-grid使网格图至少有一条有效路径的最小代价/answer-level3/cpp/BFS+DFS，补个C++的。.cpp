### 解题思路
这题要注意的是图的每个“节点”是由从当前节点开始所能走到的所有之前没有遍历过的点构成的，思路和题解中其他人的无二。
![image.png](https://pic.leetcode-cn.com/4f39fedcdb964b513f2b4c58bc0ecca99a278c792c9b726bdd42558b5cbf50e2-image.png)


### 代码

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid.front().size();
        vector<vector<int>> flags(m, vector<int>(n, 0));
        vector<vector<pair<int, int>>> q(1);
        int cnt = 0;
        if(bulidNode(0, 0, m, n, q.back(), flags, grid))
            return cnt;

        while(!q.empty())
        {
            ++cnt;
            vector<vector<pair<int, int>>> tempQ;
            for(const auto& node: q)
            {
                for(const auto& p: node)
                {
                    for(int i=0;i<4;++i)
                    {
                        int tr=p.first+dr[i], tc=p.second+dc[i];
                        if(check(tr, tc, m, n) && flags[tr][tc] == 0)
                        {
                            tempQ.push_back(vector<pair<int, int>>());
                            if(bulidNode(tr, tc, m, n, tempQ.back(), flags, grid))
                                return cnt;

                            if(tempQ.back().empty())
                                tempQ.pop_back();
                        }
                    }
                }
            }
            q = std::move(tempQ);
        }
        return -1;
    }

    bool bulidNode(int r, int c, int m, int n, vector<pair<int, int>>& node, vector<vector<int>>& flags, 
        vector<vector<int>>& grid)
    {
        while(check(r, c, m, n))
        {
            auto p = make_pair(r, c);
            if(flags[r][c] == 0)
            {
                if(r==m-1&&c==n-1)
                    return true;

                node.push_back(p);
                flags[r][c] = 1;
            }
            else
                break;

            int id = grid[r][c]-1;
            r += dr[id];
            c += dc[id];
        }
        return false;
    }
    
    bool check(int r, int c, int rm, int cm)
    {
        return r>=0&&r<rm&&c>=0&&c<cm;
    }
    
    int dr[4]={0, 0, 1, -1};
    int dc[4]={1, -1, 0, 0,};
};
```