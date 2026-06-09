

#### 正常的BFS解法需要用到一个`dis`数组记录每个橘子腐烂的时间，这样需要额外m*n的空间。
#### 这样空间复杂度会达到`O(m*n)`，虽然队列的理论空间复杂度也是`O(m*n)`，但其实远达不到。
#### 所以这里使用两个队列来交替搜索，可以省下`dis`数组，而且空间复杂度与单队列相差不大。
#### 因为实际上，我只是把原来该放在一个队列中的东西放在了两个队列中而已。
#### 当然，我也看到一些大佬的代码甚至连队列都没有使用，直接每次都爆搜腐烂的橘子。
#### 这样的空间复杂度甚至达到了`O(1)`，但代码的可读性和长度就有点不尽人意了。
#### 我的方法算是两者折中，下面看代码吧……
```
class Solution {
    int cnt=0,ans=0,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    bool now=0;
    queue<pair<int,int > >qu[2];
public:
    void bfs(vector<vector<int>>& grid,int n){
        if(cnt<=0)return ;
        int m=grid[0].size();
        while(!qu[now].empty()){
            int x=qu[now].front().first;
            int y=qu[now].front().second;
            qu[now].pop();
            for(int i=0;i<4;++i){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m) continue;
                if(grid[xx][yy]==1){
                    --cnt;
                    grid[xx][yy]=2;
                    qu[!now].push(make_pair(xx,yy));//放在另一个里面
                }     
            }      
        }
        now=!now;//交换队列
        ++ans;     
        //如果当前队列有东西，则下一次搜索
        if(!qu[now].empty()) return bfs(grid,n); 
    }
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i )
            for(int j=0;j<grid[i].size();++j)
                if(grid[i][j]==2)qu[0].push(make_pair(i,j));
                else if(grid[i][j]==1)++cnt;
        bfs(grid,grid.size());
        return cnt?-1:ans;
    }
};
```

##### 本菜鸡的第二篇题解，大佬勿喷。