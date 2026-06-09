```
class Solution {
public:
    void func(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor)
    {
        // 同种颜色
        if(oldColor == newColor)
            return;
        int row = image.size(), col = image[0].size();
        // 自己
        if(image[sr][sc] != newColor)
        {
            image[sr][sc] = newColor;
        }
        // 上
        if(sr-1 >= 0 && image[sr-1][sc] == oldColor )
        {
            image[sr-1][sc] = newColor;
            func(image, sr-1, sc, oldColor, newColor);
        }
        // 下
        if(sr+1 < row && image[sr+1][sc] == oldColor)
        {
            image[sr+1][sc] = newColor;
            func(image, sr+1, sc, oldColor, newColor);
        }
        // 左
        if(sc-1 >= 0 && image[sr][sc-1] == oldColor)
        {
            image[sr][sc-1] = newColor;
            func(image, sr, sc-1, oldColor, newColor);
        }
        // 右
        if(sc+1 < col && image[sr][sc+1] == oldColor)
        {
            image[sr][sc+1] = newColor;
            func(image, sr, sc+1, oldColor, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        func(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};

```