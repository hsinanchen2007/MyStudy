```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m] > A[m - 1] && A[m] > A[m + 1]) return m;
            if (A[m] < A[m + 1]) l = m;
            if (A[m] < A[m - 1]) r = m;
        }
        return l;
    }
};
```