### 解题思路
是STL使用太多了吗，内存消耗的太多了，但总算是过了。
最开始记录下好橘子数，
使用队列记录腐烂橘子数以及位置，然后使用循环去记录周围被感染的橘子数和位置同时好橘子数相应减少，记录循环次数，循环终止条件是不再有新增的腐烂橘子。
循环结束后如果好橘子数大于零则返回-1，否则返回循环次数。


每日感慨一句，我怎么这么辣鸡。

### 代码

```cpp
class Solution {
public:
    queue<pair<int,int> > Q;
    int Fresho=0;
    int orangesRotting(vector<vector<int> >& grid) {
        //queue<pair<int,int>> Q;
        
        int i=0,j=0,badcount=0;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[i].size();j++){
                pair<int,int> p;
                if(grid[i][j]==2){
                    p.first=i;p.second=j;
                    Q.push(p);
                    badcount++;}
                if(grid[i][j]==1){Fresho++;}
            }

        }
        int min=0;
        do{
        int count=0;
            for(int i=0;i<badcount;i++){
                pair<int,int> temp=Q.front();
                Q.pop();
                count+=Transbad(grid,temp.first,temp.second);
            }
            badcount=count;
            min++;
        }while(badcount!=0);
        if(Fresho){return -1;}
        return min-1;
    }
    int Transbad(vector<vector<int> >& grid,int i,int j)//返回新感染的橘子数
    {
        int coun=0;
        pair<int,int> p;
        if(i>0&&grid[i-1][j]==1){
            grid[i-1][j]=2;
            coun++;Fresho--;
            p.first=i-1;p.second=j;
            Q.push(p);  }
        if(i<grid.size()-1&&grid[i+1][j]==1){
            grid[i+1][j]=2;
            coun++;Fresho--;
            p.first=i+1;p.second=j;
            Q.push(p);
            }
        if(j>0&&grid[i][j-1]==1){
            grid[i][j-1]=2;
            coun++;Fresho--;
            p.first=i;p.second=j-1;
            Q.push(p);}
        if(j<grid[i].size()-1&&grid[i][j+1]==1){
            grid[i][j+1]=2;
            coun++;Fresho--;
            p.first=i;p.second=j+1;
            Q.push(p);}
        return coun;
    }
    
};
```