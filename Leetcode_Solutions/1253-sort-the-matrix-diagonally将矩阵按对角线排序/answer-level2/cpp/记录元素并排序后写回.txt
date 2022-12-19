记录每一条对角线上的元素，排序后返回
```
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> res;
        for(int i=0;i<m;i++){
            int row=0,line=i,now=0;
            res.clear();
            while(row<n&&line<m){
                res.push_back(mat[row++][line++]);
            }
            sort(res.begin(),res.end());
            row=0,line=i;
            while(row<n&&line<m){
                mat[row++][line++]=res[now++];
            }
        }
        for(int i=1;i<n;i++){
            int row=i,line=0,now=0;
            res.clear();
            while(row<n&&line<m){
                res.push_back(mat[row++][line++]);
            }
            sort(res.begin(),res.end());
            row=i,line=0;
            while(row<n&&line<m){
                mat[row++][line++]=res[now++];
            }
        }
        return mat;
    }
};
```
