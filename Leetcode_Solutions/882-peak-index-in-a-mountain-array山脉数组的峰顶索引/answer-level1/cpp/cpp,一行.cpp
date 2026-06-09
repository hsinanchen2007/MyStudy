```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return std::distance(A.cbegin(), std::max_element(A.cbegin(), A.cend()));
    }
};
```
