```
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
         int m=A.size();
         int n=A[0].size();
         for(int i=0;i<m;i++) {
             if(A[i][0]==0) {   // 第一个为0才可能翻转
                 for(int j=0;j<n;j++) {
                     A[i][j]^=1;
                 }
             }
         }
         for(int j=1;j<n;j++) {
             int cnt=0;
             for(int i=0;i<m;i++) {
                 if(A[i][j]==0) {     
                     cnt++;
                 }
             }
             if(cnt>m-cnt) {           // 每一列（排除第一列），0比1多，才可能翻转。
                for(int i=0;i<m;i++) {
                    A[i][j]^=1;
                } 
             }
         }
         long long mul=1;
         long long res=0;
         for(int j=n-1;j>=0;j--) {
             for(int i=0;i<m;i++) {
                 res+=(mul*A[i][j]);
             }
             mul<<=1;
         }
         return res;
    }
};
```
