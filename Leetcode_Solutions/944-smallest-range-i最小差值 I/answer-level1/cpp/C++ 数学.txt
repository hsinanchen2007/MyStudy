```c++
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int a = *max_element(A.begin(), A.end());
        int b = *min_element(A.begin(), A.end());
        return (a - b < 2 * K) ? 0 : a - b - 2 * K;
    }
};
```