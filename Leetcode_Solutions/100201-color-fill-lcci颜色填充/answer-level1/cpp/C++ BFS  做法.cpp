### 解题思路
由于这道题 题意不清 所以浪费了好久时间  应该再加一个条件 和image[sr][sc]的值相等会改变颜色 否则颜色不变

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size(),m=image[0].size();
        int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1} ;

        vector<vector<bool> > st(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(image[i][j] == image[sr][sc])  st[i][j] =true;
        
            
        queue< pair<int,int> > q;
        q.push( pair<int,int>(sr,sc) );
        image[sr][sc]=newColor;
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=dx[i]+t.first,y=dy[i]+t.second;
                if(x<0 || x>=n ||y<0 ||y>=m  ||st[x][y]==false)  continue ;
                image[x][y]=newColor;
                st[x][y]=false;
                q.push(pair<int,int>(x,y)) ;
            }
        }

        return  image;
    }
};
```