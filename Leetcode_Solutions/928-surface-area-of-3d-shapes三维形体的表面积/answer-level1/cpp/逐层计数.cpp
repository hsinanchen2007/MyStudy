逐层扫描，横向扫描时方块从出现到消失各计加一，纵向扫描类似。
```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum=0,ones=0,max=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]>max) max=grid[i][j];
                if(grid[i][j]>0) ++ones;
            }
        }
        sum+=ones*2;
        
        return sum+scanh(grid,max)+scanv(grid,max);
    }
    int scanh(vector<vector<int>>& grid,int n){
        int cnt[50]={0};
        int flag[50]={0};
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                    for(int k=0;k<grid[i][j];++k){
                        if(flag[k]==0){
                            ++cnt[k];
                            flag[k]=1;
                        }
                        if(j==(grid[0].size()-1)){
                            ++cnt[k];
                            flag[k]=0;
                        }
                    }
                    for(int k=grid[i][j];k<n;++k){
                        if(flag[k]==1 ){
                            ++cnt[k];
                            flag[k]=0;
                        }
                    }
            }
        }
        int sum=0;
        for(int x:cnt){
            sum+=x;
        }
        return sum;
    }
    int scanv(vector<vector<int>>& grid,int n){
        int cnt[50]={0};
        int flag[50]={0};
        for(int i=0;i<grid[0].size();++i){
            for(int j=0;j<grid.size();++j){
                    for(int k=0;k<grid[j][i];++k){
                        if(flag[k]==0){
                            ++cnt[k];
                            flag[k]=1;
                        }
                        if(j==(grid.size()-1)){
                            ++cnt[k];
                            flag[k]=0;
                        }
                    }
                    for(int k=grid[j][i];k<n;++k){
                        if(flag[k]==1 ){
                            ++cnt[k];
                            flag[k]=0;
                        }
                    }
            }
        }
        int sum=0;
        for(int x:cnt){
            sum+=x;
        }
        return sum;
    }
};
```
