### 解题思路
1、先排序
2、让后面一个元素比前一个大1就是最少的增加次数

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
         if(A.size() <= 1){
             return 0;
         }
         sort(A.begin(), A.end());
         int movenum = 0;
         int diff = 0;
         for(int i = 1;i<A.size();i++){
             if(A[i] > A[i-1]){
                 continue;
             }else{
                 diff = A[i-1] -A[i];
                 A[i] = A[i-1] + 1;
                 movenum += diff;
                 movenum+=1;
                 
                 
             }
         }

         return movenum;
    }
};
```