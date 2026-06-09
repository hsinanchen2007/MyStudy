### 解题思路
1.用两个队列，一个curQ放当前的腐烂点，nextQ放与curQ相邻的新鲜水果。用time记录nextQ和curQ的交换次数

2.将腐烂时间看成是新鲜水果与腐烂水果之间的最短距离，最短距离中最大者为扩散时间。用一个curQ和dis数组保存距离。

### 代码

```cpp

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>current,next,emptyQue;

        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2)
                    next.push(make_pair(i,j));
            }
        }

        int time=0;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        pair<int,int>temp;
        while(true){
            current=next;
            next=emptyQue;
            while(!current.empty()){
                temp=current.front();
                current.pop();
                for(int i=0;i<4;i++){
                    int x=temp.first+dir[i][0];
                    int y=temp.second+dir[i][1];
                    if(x>=0&&x<row&&y>=0&&y<col){
                        if(grid[x][y]==1){
                            grid[x][y]=2;
                            next.push(make_pair(x,y));
                        }
                    }
                }
            }
            if(!next.empty())
                time++;
            else break;
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>current;
        int freshNum=0,maxDis=0;
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>>dis(row,vector<int>(col,INT_MAX-1));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    current.push(make_pair(i,j));
                    dis[i][j]=0;
                }

                else if(grid[i][j]==1)freshNum++;
            }
        }

        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        pair<int,int>temp;
        while(!current.empty()){
            temp=current.front();
            current.pop();
            for(int i=0;i<4;i++){
                int x=temp.first+dir[i][0];
                int y=temp.second+dir[i][1];
                if(x>=0&&x<row&&y>=0&&y<col){
                    if(grid[x][y]==1){
                        freshNum--;
                        maxDis=dis[temp.first][temp.second]+1;
                        grid[x][y]=2;
                        dis[x][y]=dis[temp.first][temp.second]+1;
                        current.push(make_pair(x,y));
                    }
                }
            }
        }

        if(freshNum!=0)return -1;
        else return maxDis;
    }
};
```