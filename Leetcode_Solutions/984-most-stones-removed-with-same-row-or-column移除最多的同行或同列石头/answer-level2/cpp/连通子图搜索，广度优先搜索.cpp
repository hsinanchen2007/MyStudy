绝大部分题解都用了并查集，我这里给出一个广度优先搜索方法。
```
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> pointsRowMajor;
        unordered_map<int, vector<int>> pointsColMajor;
        vector<bool> visited(10000, false);
        for(const auto& stone: stones)
        {
            pointsRowMajor[stone[0]].push_back(stone[1]);
            pointsColMajor[stone[1]].push_back(stone[0]);
        }
        int moves = 0;
        for(auto it = pointsRowMajor.begin(); it != pointsRowMajor.end(); it++)
        {
            if(visited[it->first]) continue;
            visited[it->first] = true;
            queue<int> rows;
            rows.push(it->first);
            while(!rows.empty())
            {
                int row = rows.front();
                rows.pop();
                moves += pointsRowMajor[row].size();
                for(const int col: pointsRowMajor[row])
                {
                    for(const int r: pointsColMajor[col])
                    {
                        if(visited[r]) continue;
                        rows.push(r);
                        visited[r] = true;
                    }
                }
            }
            moves--;
        }
        return moves;
    }
};
```
