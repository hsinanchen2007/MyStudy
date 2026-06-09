```
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty()) return {};
        int n = a.size();
        vector<int> le(n,1), ri(n,1), res(n);
        for(int i=1; i<n; i++)
            le[i] = le[i-1] * a[i-1];
        for(int i=n-2; i>=0; i--)
            ri[i] = ri[i+1] * a[i+1];
        for(int i=0; i<n; i++)
            res[i] = le[i] * ri[i];
        return res;
    }
};
```
