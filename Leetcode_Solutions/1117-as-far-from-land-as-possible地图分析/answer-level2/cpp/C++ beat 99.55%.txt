```

    class Solution {
    public:
        int maxDistance(vector<vector<int>>& grid) {
            int flag = 1 ,i,j,k=2,l;
            int rn = grid.size(),cn = grid[0].size();
            while(flag){
                flag =0;
                for(i =0;i<rn;i++){
                    for(j=0;j<cn;j++){
                        if(grid[i][j]==0)continue;
                        if(grid[i][j]==k-1){
                            if(i-1>=0&& grid[i-1][j]==0){
                                grid[i-1][j]=k;
                                flag=1;
                            }
                            if(i+1<rn&&grid[i+1][j]==0){
                                grid[i+1][j]=k;
                                flag=1;
                            }
                            if(j-1>=0&&grid[i][j-1]==0){
                                grid[i][j-1]=k;
                                flag=1;
                            }
                            if(j+1<cn&&grid[i][j+1]==0){
                                grid[i][j+1]=k;
                                flag=1;
                            }
                        }
                    }
                }
                if(flag){
                    k++;
                }
            }
            cout<<k<<endl;
            if(k-2==0)return -1;
            return k-2;
        }
    };
```
