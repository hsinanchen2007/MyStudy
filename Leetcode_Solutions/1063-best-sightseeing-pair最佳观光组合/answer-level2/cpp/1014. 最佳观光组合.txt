```
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n=A.size();
        int maxvalue=A[0];
        int res=INT_MIN;

        for(int i=1;i<n;++i)
        {
            res=max(res,A[i]-i+maxvalue);
            maxvalue=max(maxvalue, A[i]+i);
        }

        return res;
    }
};
```
