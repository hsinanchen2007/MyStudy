```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i = 0;i < n;++i)
            A[i+m] = B[i];
        sort(A.begin(),A.end());
    }
};
```