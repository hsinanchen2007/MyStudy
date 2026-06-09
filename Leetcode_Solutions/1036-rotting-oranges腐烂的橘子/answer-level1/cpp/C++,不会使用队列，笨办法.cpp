不会使用队列存储坐标集合，就只能用这种笨办法，这次学到了。
C++的矢量和python的数组使用体验差好多。
```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        int flag=1;
        vector<int> d(n,0);
        do{
        vector<vector<int>> map(m,d);
    flag=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                if((i-1>=0&&grid[i-1][j]==2)||(i+1<m&&grid[i+1][j]==2)||(j-1>=0&&grid[i][j-1]==2)||(j+1<n&&grid[i][j+1]==2)) map[i][j]=1;
            }
        }
    }
    for(int i=0;i<m&&flag;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]){
                cnt++;
                flag=0;
                break;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]) grid[i][j]=2;
        }
    }
    }while(!flag);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1) {cnt=-1;break;}
        }
    }
    return cnt;
    }
};
```
