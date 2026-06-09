```
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        return max(0, *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end()) - K - K);
    }
};
```
