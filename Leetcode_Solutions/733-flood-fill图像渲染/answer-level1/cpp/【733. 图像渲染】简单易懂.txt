## 思路
### 代码
```c++
class Solution {
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int t = image[sr][sc];
        dfs(image, t, sr, sc, newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int t, int i, int j, int newColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor) {
            return;
        }
        if (image[i][j] == t) {
            image[i][j] = newColor;
            for (auto d : dir) {
                dfs(image, t, i + d[0], j + d[1], newColor);
            }
            return;
        }
    }
};
```
