水平有限，第一时间想到的方法比较笨重。
通过深度优先搜索（递归版）所有可能路径。
每次探索，把起点变成不可经过的方块（-1），把周围的空闲方块改成新起点。
递归终止于起点被堵死或没有空闲方块。
```
class Solution {
public:
    int len1;
    int len2;
    int uniquePathsIII(vector<vector<int>>& grid,int code=1) {
        if(code){//第一次记录边长
            len1=grid.size();
            len2=grid[0].size();
        }
        int i1,i2,j1,j2;//起点(j1,i2),终点(j2,i2)
        int blank=0;//可走过方块数目
        for(int i=0;i<len1;++i){
            for(int j=0;j<len2;++j){
                switch(grid[i][j]){//检查类型
                    case 1:
                        i1=i;
                        j1=j;
                        break;
                    case 2:
                        i2=i;
                        j2=j;
                        break;
                    case 0:
                        ++blank;
                        break;
                }
            }
        }
        if(blank==0&&(abs(i1-i2)+abs(j1-j2)==1)) return 1;//完美路径
        if(blank==0) return 0;//走完了但是走错了
        int ans=0;
        //int flag=1;
        //flag:起点是否被堵死，但是堵死时，ans==0，且无论如何都要检查四个方向，也节约不了时间
        if(i1>0&&grid[i1-1][j1]==0){
            //flag=0;
            auto T1grid=grid;
            T1grid[i1][j1]=-1;
            T1grid[i1-1][j1]=1;
            ans+=uniquePathsIII(T1grid,0);
        }
        if(j1>0&&grid[i1][j1-1]==0){
            //flag=0;
            auto T2grid=grid;
            T2grid[i1][j1]=-1;
            T2grid[i1][j1-1]=1;
            ans+=uniquePathsIII(T2grid,0);
        }
        if(i1<len1-1&&grid[i1+1][j1]==0){
            //flag=0;
            auto T3grid=grid;
            T3grid[i1][j1]=-1;
            T3grid[i1+1][j1]=1;
            ans+=uniquePathsIII(T3grid,0);
        }
        if(j1<len2-1&&grid[i1][j1+1]==0){
            //flag=0;
            auto T4grid=grid;
            T4grid[i1][j1]=-1;
            T4grid[i1][j1+1]=1;
            ans+=uniquePathsIII(T4grid,0);
        }
        //if(flag) return 0;
        return ans;
    }
};
```
