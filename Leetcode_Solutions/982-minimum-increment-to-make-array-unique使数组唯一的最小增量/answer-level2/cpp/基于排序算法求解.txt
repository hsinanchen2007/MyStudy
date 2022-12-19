

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
       int res=0;
       sort(A.begin(),A.end());
       for(int i=1;i<A.size();i++){
           if(A[i]==A[i-1]){
                A[i]++;
                res++;
            }
            if(A[i]<A[i-1]){
                res+=A[i-1]-A[i]+1;
                A[i]=A[i-1]+1;
            }
       }
       return res;

    }
};
```