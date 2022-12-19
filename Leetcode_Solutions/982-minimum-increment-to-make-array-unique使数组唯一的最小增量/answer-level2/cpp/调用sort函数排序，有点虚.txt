```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() < 2) return 0;
        sort(A.begin(), A.end());
        int res = 0;
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i + 1] == A[i]){
                res += 1;
                A[i + 1] += 1;
            }else if(A[i + 1] < A[i]){
                res += A[i] - A[i + 1] + 1;
                A[i + 1] = A[i] + 1;
            }
        } 
        return res;
    }
};
```
