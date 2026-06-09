题意是要把和初始坐标点颜色相同的，并且与它联通的点的颜色改成新的颜色。
其实就是找上下左右与它值相同的坐标点，直接BFS：
```C++
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }

        int m = image.size();    
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.emplace(make_pair(sr, sc));
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = newColor;
            for (auto& dir : dirs) {
                int rowT = row + dir[0];
                int colT = col + dir[1];
                if (rowT >= 0 && rowT < m && colT >= 0 && colT < n && image[rowT][colT] == color) {
                    q.emplace(make_pair(rowT, colT));
                }
            }
            
        }
        return image;
    }
};
```
