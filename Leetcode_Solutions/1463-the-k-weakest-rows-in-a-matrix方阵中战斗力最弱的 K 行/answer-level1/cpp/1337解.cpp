### 解题思路
判断列优先出现0的行号，注意长度。

### 代码

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> weakrow;
        int flag[m];
        memset(flag,0,sizeof(int)*m);
        for(int i=0;i<n;i++){
            if(weakrow.size()>=k)break;
            for(int j=0;j<m;j++){
                if(weakrow.size()>=k)break;
                if(flag[j]==0&&mat[j][i]==0){
                    weakrow.push_back(j);
                    flag[j]=1;
                } 
            }    
        }
        if(weakrow.size()<k)
        for(int j=0;j<m;j++){
            if(weakrow.size()>=k)break;
            if(!flag[j]){
                weakrow.push_back(j);
                flag[j]=1;
            }
        }
        return weakrow;
    }
};
```