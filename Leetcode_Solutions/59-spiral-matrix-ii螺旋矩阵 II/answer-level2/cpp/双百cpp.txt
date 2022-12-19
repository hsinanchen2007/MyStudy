
### 代码

```cpp
class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector(n,-1));
        int ind=2,i=0,j=0,dir=0;
        ret[0][0]=1;
        for(;;){
            //cout<<ind<<' ';
            int ni=i+dx[dir],nj=j+dy[dir];
            if(ni>=0&&nj>=0&&ni<n&&nj<n&&ret[ni][nj]==-1){
                i=ni;j=nj;
                ret[i][j]=ind++;
            }else{
                int k=0;
                for(;k<4;k++){
                    ni=i+dx[k];
                    nj=j+dy[k];
                    if(ni>=0&&nj>=0&&
                       ni<n&&nj<n&&ret[ni][nj]==-1)
                    {dir=k;break;}
                }
                if(k==4)break;
            }
        }
        return ret;
    }
};
```