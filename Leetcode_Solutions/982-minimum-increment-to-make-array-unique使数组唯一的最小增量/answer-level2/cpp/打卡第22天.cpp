先排序，再逐个更新后面的值
```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<=1) return 0;
        sort(A.begin(), A.end());
        int count = 0;
        for(int i=1;i<A.size();i++){
           
            if(A[i-1]>=A[i]){
                
           int n= A[i-1] - A[i] +1;
            
            A[i] += n;
            count += n;
            }


        }
        return count;

    }
};
```
