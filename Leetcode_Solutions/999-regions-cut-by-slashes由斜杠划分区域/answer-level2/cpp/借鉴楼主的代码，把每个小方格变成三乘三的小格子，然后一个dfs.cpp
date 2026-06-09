# 标题*斜体*
一个巧妙的思路。将 / 转为

001
010
100.

空格转为
000
000
000

\转为
100
010
001。

将原来n*n方格转为3n * 3n 方格。求0的连通量个数。

比如

"//"
"/ "

转化为

001001
010010
100100
001000
010000
100000

代码如下:
```
struct direct
{
	int ax, ay;
}direct[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };//每个更小格子的四个方位
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N=grid.size();
        vector<vector<int>> mygrid(N*3,vector<int>(N*3,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]=='/')
                {
                    mygrid[i*3][j*3+2]=1;
                    mygrid[i*3+1][3*j+1]=1;
                    mygrid[i*3+2][j*3]=1;
                }
                if(grid[i][j]=='\\')
                {
                    mygrid[i*3+1][j*3+1]=mygrid[i*3][j*3]=1;
                    mygrid[i*3+2][j*3+2]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<N*3;i++)
        {
            for(int j=0;j<N*3;j++)
            {
                if(mygrid[i][j]==0)
                {
                    dfs(mygrid,i,j,N);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& mygrid,int i,int j,int N)
    {
        //遍历前后左右，将为0的格子标记为2，表示已访问
        int p=i,q=j;
        for(int k=0;k<4;k++)
        {
            p=p+direct[k].ax;
            q=q+direct[k].ay;
            if(p>=0 && p<N*3 && q>=0 && q<3*N && mygrid[p][q]==0)
            {
                mygrid[p][q]=2;
                dfs(mygrid,p,q,N);
            }
            p=i;
            q=j;
        }
    }
};
```
