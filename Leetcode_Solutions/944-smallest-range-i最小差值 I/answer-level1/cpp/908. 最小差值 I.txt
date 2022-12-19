```
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int n=A.size();
        int a_min=A[0];
        int a_max=A[0];
        for(int i=1;i<n;++i)
        {
            a_min=min(a_min,A[i]);
            a_max=max(a_max,A[i]);
        }
        return max(a_max-a_min-K-K,0);
    }
};
```
