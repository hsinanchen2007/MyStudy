```
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n=A.size();

        stable_sort(A.begin(),A.end());

        int res=A[n-1]-A[0];

        int tmp_min=A[0]+K;
        int tmp_max=A[n-1]-K;

        for(int i=1;i<n;++i)
        {
            res=min(res,max(tmp_max,A[i-1]+K)-min(tmp_min,A[i]-K));
        }

        return res;
    }
};
```

借用@Setul 的图示写的……
