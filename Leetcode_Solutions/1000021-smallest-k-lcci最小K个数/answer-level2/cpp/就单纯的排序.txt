```
class Solution {
public:
    vector<int> smallestK(vector<int>& A, int k) {
        sort(A.begin(),A.end());
        vector<int> Ans;
        for (int i=0;i<k;++i) Ans.push_back(A[i]);
        return Ans;
    }
};
```
