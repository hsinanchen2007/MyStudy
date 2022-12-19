编写dfs函数以（nr，nc）为起点分上、下、左、右四个方向进行image的遍历。
需要注意一种特殊情况，如果newColor的数值与当前像素的值一样，则直接返回image即可。
如果不对这种情况进行讨论，则会发生无限循环

class Solution {
public:
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int color = image[sr][sc];
        if(newColor == color)
        {}
        else
            dfs(image, sr, sc, newColor, color);
        
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int color)
    {
        
        
        int row = image.size();
        int col = image[0].size();
        
        
        image[sr][sc] = newColor;
        if(sr-1 >= 0 && image[sr-1][sc] == color) dfs(image, sr-1, sc, newColor, color);
        if(sr+1 <row && image[sr+1][sc] == color) dfs(image, sr+1, sc, newColor, color);
        if(sc-1 >= 0 && image[sr][sc-1] == color) dfs(image, sr, sc-1, newColor, color);
        if(sc+1 <col && image[sr][sc+1] == color) dfs(image, sr, sc+1, newColor, color);
    }
    
};