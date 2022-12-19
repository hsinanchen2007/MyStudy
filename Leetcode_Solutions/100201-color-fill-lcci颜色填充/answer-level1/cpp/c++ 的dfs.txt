```
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])   return image;
        else dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int c){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if(image[sr][sc] == c){
            image[sr][sc] = newColor;
            dfs(image, sr + 1, sc, newColor, c);
            dfs(image, sr - 1, sc, newColor, c);
            dfs(image, sr, sc - 1, newColor, c);
            dfs(image, sr, sc + 1, newColor, c);
        }
    }
};
```
