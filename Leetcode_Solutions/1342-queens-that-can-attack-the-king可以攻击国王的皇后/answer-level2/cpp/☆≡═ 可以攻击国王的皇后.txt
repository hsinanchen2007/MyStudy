以国王为中心，逆时针遍历8个方向，寻找皇后。
```
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(const vector<vector<int>>& queens,
                                            const vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<bool>> has_queen(n, vector<bool>(n, false));
        for (const auto& q : queens)
            has_queen[q[0]][q[1]] = true;
        const int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        for (int dir = 0; dir < 8; ++dir)
            for (int r=king[0], c=king[1]; suitable(r,c); r+=dr[dir], c+=dc[dir])
                if (has_queen[r][c]) {
                    ans.push_back({r, c});
                    break;
                }
        return ans;
    }
    
private:
    static const int n = 8;
    static inline bool suitable(const int r, const int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    }
};
```
