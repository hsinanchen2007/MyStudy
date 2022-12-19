这道题本身来讲是一道大水题，思路就只是简单的暴力dfs就可以，但是我本人在做的时候却感觉T了好几次。

现在我来说说我觉得你可能出现TLE的情况。

首先是dfs入口问题，我一开始是将所有可能入口存入一个队列中，这里面的各种接口虽然对渐进复杂度没有影响，但是会加大常数。这里的优化是直接扫描时就开始dfs。

其次时访问数组vis的问题，这里并不需要每次dfs都将它重新置零，因为dfs的特性，你在本节点访问结束之后一定会将该位置的vis重新置为0，如果没有重新置零的情况只能是找到了可行解，可以提前结束了，那么就根本不需要再次进行dfs，vis数组也就没用了。所以vis只需要进行一次置零。

再次，是剪枝的问题，朴素的，你当然应该想到位置越界、该位置不能对应word种的下一个字符、已经访问过这几种情况。但是还有一种剪枝是什么时候提前结束。在对该节点的四个方向进行搜索的时候，只需要其中一个方向可以返回可行解就可以结束了。这种剪枝可以是通过多次判断、逻辑表达式的短路求值等方法进行。详情请看代码注释。
当然这种剪枝只是在有可行解的情况下，如果没有可行解，那么复杂度依旧会指数增加，存在上界。在本题最后几个样例中85-87，如果这几个样例都没有解，那么你看到的绝大部分题解都能被hack掉。

```cpp
class Solution {

public:
    static const int maxn = 202;
    bool vis[maxn][maxn];

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int n,m;
    int dep;
    vector<vector<char>> board;
    string word;

    bool dfs(int sx,int sy,int dist){
        //cout<<word[p.pos]<<" ";
        if(dist>=dep-1)    return true;
        int x,y;
        bool f=0;
        for(int i=0;i<4;i++){
            x=sx+dx[i];
            y=sy+dy[i];
            if((x<n)&&(x>=0)&&(y<m)&&(y>=0)){
                if(!vis[x][y]&& (board[x][y]==word[dist+1])){
                    vis[x][y]=1;
                    //可以用短路求值枚举四个方向，用||连起来
                    f=dfs(x,y,dist+1);
                    vis[x][y]=0;
                    //在此处要提前结束，否则最后几个样例过不了
                    if(f)   return true;
                }
            }
        }
        return f;
    }

    bool exist(vector<vector<char>>& mat, string str) {

        n=mat.size();
        m=mat[0].size();

        word=str;
        board=mat;
        dep=word.length();

        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(dfs(i,j,0)) return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};
```
![无标题.png](https://pic.leetcode-cn.com/78ed3804eb072e327b39edb59afcffcb3208d23d555724a9e2b708270ae8d4ae-%E6%97%A0%E6%A0%87%E9%A2%98.png)
