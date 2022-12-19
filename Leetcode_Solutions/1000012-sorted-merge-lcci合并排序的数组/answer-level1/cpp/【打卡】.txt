倒着插就完事了
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n)
    {
        int bi = n - 1;
        int ai = m - 1, ak = A.size() - 1;
        while(bi >= 0 && ai >= 0)
        {
            if(B[bi] >= A[ai])
                A[ak--] = B[bi--];
            else
                A[ak--] = A[ai--];
        }
        while(bi >= 0)
            A[ak--] = B[bi--];
    }
};
```
