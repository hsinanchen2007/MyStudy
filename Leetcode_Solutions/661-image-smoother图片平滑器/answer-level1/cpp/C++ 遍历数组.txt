```
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row=M.size(),col=M[0].size(),cnt;
        vector<vector<int>>temp(M);
        int x[9]={-1,-1,-1,0,0,0,1,1,1};
        int y[9]={-1,0,1,-1,0,1,-1,0,1};
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                cnt=0;
                int sum=0;
                for(int k=0;k<9;++k){
                    if(i+x[k]>=0&&i+x[k]<row&&j+y[k]>=0&&j+y[k]<col){
                        sum+=temp[i+x[k]][j+y[k]];
                        cnt++;
                    }
                }
                M[i][j]=sum/cnt;
            }
        }
        return M;
    }
};
```
对数组中的每个元素，考虑其四周的情况，逐一计算。
