```
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc])return image;
        DFS(image,sr,sc,newColor,image[sr][sc]);
        return image;
        
    }
    void DFS(vector<vector<int>>& image, int sr, int sc, int newColor,int start){
        if(image[sr][sc]==start)image[sr][sc]=newColor;
        else return;
        if(sr-1>=0)DFS(image,sr-1,sc,newColor,start);
        if(sr+1<image.size())DFS(image,sr+1,sc,newColor,start);
        if(sc-1>=0)DFS(image,sr,sc-1,newColor,start);
        if(sc+1<image[0].size())DFS(image,sr,sc+1,newColor,start);
        
    }
};
```
