```
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor)
    {
        int rows = image.size();
        int cols = image[0].size();
        if(sr<0 || sr>=rows || sc<0 || sc>=cols || image[sr][sc] != oldColor)
            return;
        image[sr][sc] = newColor;
        fill(image, sr-1, sc, oldColor, newColor);
        fill(image, sr, sc+1, oldColor, newColor);
        fill(image, sr+1, sc, oldColor, newColor);
        fill(image, sr, sc-1, oldColor, newColor);
        return;       
    }
};
```
