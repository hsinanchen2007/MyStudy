```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret;
        for(auto n:A)
        {
            ret.push_back(n*n);
        }
        sort(ret.begin(), ret.end());
        return ret;            
    }
};
```
