解题思路：递归解决（sr, sc）的上下左右四个方向，用一个二维数组来标记已被访问过的点。
```
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int a = image.size(), b = image[0].size();
        vector<vector<int>> mark(a, vector<int>(b));
        floodFill(image, mark, sr, sc, image[sr][sc], newColor, a, b);
        return image;
    }
    void floodFill(vector<vector<int>>& image, vector<vector<int>>& mark, int sr, int sc, 
                    int oldColor, int newColor, int a, int b) {
        if(sr < 0 || sc < 0 || sr == a || sc == b || mark[sr][sc] == 1)
            return;
        mark[sr][sc] = 1;
        if(image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            floodFill(image, mark, sr - 1, sc, oldColor, newColor, a, b);
            floodFill(image, mark, sr, sc + 1, oldColor, newColor, a, b);
            floodFill(image, mark, sr + 1, sc, oldColor, newColor, a, b);
            floodFill(image, mark, sr, sc - 1, oldColor, newColor, a, b);
        }
    }
};
```
