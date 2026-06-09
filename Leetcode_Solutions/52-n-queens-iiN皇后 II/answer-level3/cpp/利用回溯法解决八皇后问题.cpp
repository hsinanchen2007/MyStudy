### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   bool Place(int k,int i,vector<int> &x){
       for(int j=0;j<k;j++)
            if((x[j]== i) || (abs(x[j]-i) == abs(j-k))) return false;
        return true;
   }
   void NQueens(int k,int n,vector<int> &x,int &y){
       for(int i=0;i<n;i++){
           if(Place(k,i,x)){
               x[k] = i;
               if(k == n-1){
                 y++;
               }else{
                   NQueens(k+1,n,x,y);
               }
           }
       }
   }
    int totalNQueens(int n) {
        vector<int> x(n,-1);
        int y=0;
        NQueens(0,n,x,y);
        return y;
    }
};
```