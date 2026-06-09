![QQ20191109-0.png](https://pic.leetcode-cn.com/1a7bd853f63169bd34e8aadc0277f964045c6452df9290a64252c0c3d6e00a50-QQ20191109-0.png)


```
class Solution {
public:
    int find(int x){
        if(uset[x]<0) return x;  //找到根节点，返回根节点的下标，只有根节点的uset是负数，其他节点的uset是根节点的下标
        uset[x] = find(uset[x]);  //递归地找根节点，且可以将查找路径上的所有节点的uset都直接指向根节点，进行了路径压缩
        return uset[x];
    }
    void Union(int x,int y){
        if((x=find(x))==(y=find(y))) return ;  //两个节点已经在同一棵树上，已联通
        if(uset[x]<uset[y])
            uset[x]+=uset[y], uset[y]=x;
        else
            uset[y]+=uset[x], uset[x]=y;
        ans--;    //每发生一次合并，不联通的部分个数减少一
        return ;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();  //n*n
        ans=n*n*4;  //一共n*n个正方形，每个正方形分成四个格子
        //每个正方形被分成上下左右四个小格子 下标是  i*4*n+j*4+0 ... i*4*n+j*4+3
        for(int i=0;i<n*n*4;i++) 
        {
            uset[i]=-1;  //并查集初始化，-1表示已自己为根结点构建树
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)   //每个格子中只可能是对角线有边来间隔，将每个格子向下和向右合并
            {
                if(i+1<n)    //可以向下合并
                {
                    Union(i*4*n+j*4+1, (i+1)*4*n+j*4);  //i行j列的下格子和i+1行j列的上格子进行合并
                }
                if(j+1<n)    //可以向右合并
                {
                    Union(i*4*n+j*4+3, i*4*n+(j+1)*4+2); //i行j列的右格子和i行j+1列的左格子进行合并
                }
                if(grid[i][j]==' ')
                {
                    Union(i*4*n+j*4, i*4*n+j*4+3);   //单个正方形内部的上和右进行合并
                    Union(i*4*n+j*4+1, i*4*n+j*4+2); //单个正方形内部的左和下进行合并
                    Union(i*4*n+j*4+1, i*4*n+j*4+3); //单个正方形内部的四个格子都合并了
                }
                else if(grid[i][j]=='/')
                {
                    Union(i*4*n+j*4+1, i*4*n+j*4+3);   //下和右合并
                    Union(i*4*n+j*4, i*4*n+j*4+2);     //左和上合并
                }
                else if(grid[i][j]=='\\')
                {
                    Union(i*4*n+j*4, i*4*n+j*4+3);   //上和右合并
                    Union(i*4*n+j*4+1, i*4*n+j*4+2); //下和左合并
                }
            }
        }
        return ans;
    }
    private:
    int uset[3605],ans;
};
```
