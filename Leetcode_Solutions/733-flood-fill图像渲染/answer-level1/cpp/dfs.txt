```
class Solution {
public:
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size(), colum = image[0].size();
        int color = image[sr][sc];
        backtrack(image,sr,sc,row,colum,color,newColor);
        return image;
    }
    void backtrack(vector<vector<int>>& image, int i, int j, int& row, int& colum, int& color, int& newColor) {
        if (i<0 || j<0 || i >= row || j >= colum || image[i][j] != color || image[i][j] == newColor)
            return;
        image[i][j] = newColor;
        for (int k=0;k<4;k++)
            backtrack(image,i+dirs[k][0],j+dirs[k][1],row,colum,color,newColor);
    }
};
```
