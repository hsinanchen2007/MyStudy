```
int cr, cy;
bool cmp(vector<int>& p1, vector<int>& p2)
{
    return abs(p1[0]-cr) + abs(p1[1]-cy) < abs(p2[0]-cr) + abs(p2[1]-cy);
}

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
                res.push_back({i,j});
        }
        cr = r0, cy = c0;
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};
```
