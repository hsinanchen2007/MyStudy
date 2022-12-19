记录各对角线地址，排序后再存入各地址
![image.png](https://pic.leetcode-cn.com/48683b0e3976977527d54d05a0237ace6a527005941aa257a7333dba86bc727b-image.png)

```
class Solution {
public:
    void helper(vector<int*>&addres){
        vector<int>addCmp;
        for(int i=0;i<addres.size();i++){
            addCmp.push_back(*addres[i]);
        }
        sort(addCmp.begin(),addCmp.end());
        for(int i=0;i<addres.size();i++){
            *addres[i] = addCmp[i];
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        if(!m)return {};
        int n = mat[0].size();
        int col = n-1,row = 0;
        while(col >= 0){
            int i = row,j = col;
            vector<int*>addres;
            while(i<m && j<n){
                addres.push_back(&mat[i][j]);
                i ++;
                j ++;
            }
            helper(addres);
            col --;
        }
        row = 1;
        col = 0;
        while(row < m){
            int i = row,j = col;
            vector<int*>addres;
            while(i<m && j<n){
                addres.push_back(&mat[i][j]);
                i ++;
                j ++;
            }
            helper(addres);
            row ++;
        }
        return mat;
    }
};
```
