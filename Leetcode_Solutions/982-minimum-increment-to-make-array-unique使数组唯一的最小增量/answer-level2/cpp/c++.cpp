```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()==0) return 0;
        sort(A.begin(),A.end());
        int res = 0;
        int prev = A[0];
        int counts = 0;
        for(int i=1;i<A.size();i++){
            if(prev>=A[i]){
                counts = prev-A[i]+1;
                A[i]=prev+1;
                res += counts;
            }
            prev = A[i];//更新当前数
        }
        return res;
    }
};
```
