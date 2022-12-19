`void dfs(vector<vector<int>>& image,int n,int m,int x,int y,int oldColor,int newColor){
        if(x<0 || x==n) return;//x y 出界return
        if(y<0 || y==m) return;
        if(image[x][y]!=oldColor) return;//颜色不一样 retrun
        image[x][y]=newColor;
        dfs(image,n,m,x-1,y,oldColor,newColor);
        dfs(image,n,m,x+1,y,oldColor,newColor);
        dfs(image,n,m,x,y-1,oldColor,newColor);
        dfs(image,n,m,x,y+1,oldColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        int oldColor=image[sr][sc];
        if(oldColor==newColor) return image;
        dfs(image,n,m,sr,sc,oldColor,newColor);
        return image;
    }