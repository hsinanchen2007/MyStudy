### 解题思路
看了大佬的记录左右上的长度的解法后写了个二维的解法，便于理解吧

### 代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        vector<vector<int>> leftlen(m,vector<int>(n,-1));
        vector<vector<int>> highlen(m,vector<int>(n,0));
        vector<vector<int>> rightlen(m,vector<int>(n,n));
        int maxarea=0;
        for(int i=0;i<m;i++){
            int bound=-1;
            for(int j=0;j<n;j++){
                
                if(matrix[i][j]=='1'){
                    if(i!=0) leftlen[i][j] =max(bound,leftlen[i-1][j]);
                    else leftlen[i][j]=bound;
                    if(i==0) highlen[i][j]=1;
                    else highlen[i][j]=highlen[i-1][j]+1;
                }
                else {
                    leftlen[i][j]=-1;
                    bound=j;
                    highlen[i][j]==0;
                }
            }
            bound=n;
            for(int j=n-1;j>=0;j--){
                
                if(matrix[i][j]=='1'){
                    if(i!=0) rightlen[i][j]=min(rightlen[i-1][j],bound);
                    else rightlen[i][j]=bound;

                }
                else {
                    rightlen[i][j] = n; 
                    bound = j;
                }
            }
            for(int j=0;j<n;j++)
            {
                
                int area=highlen[i][j]*(rightlen[i][j]-leftlen[i][j]-1);
                maxarea=max(area,maxarea);
            }
        }
        return maxarea;
    }
};
```