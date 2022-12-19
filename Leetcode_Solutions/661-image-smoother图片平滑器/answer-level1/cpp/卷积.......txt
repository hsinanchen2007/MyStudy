```c++
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans(M);
        int R=M.size(),C=M[0].size();
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                vector<int> k1={i-1,i,i+1},k2={j-1,j,j+1};
                int k=0,cnt=0;
                for (auto a:k1){
                    for (auto b:k2){
                        if ((a<R && a>=0) && (b>=0 && b<C)){
                            cnt++;
                            k+=M[a][b];
                        }
                    }
                }
                ans[i][j]=k/cnt;
            }
        }
        return ans;

    }
};
```
