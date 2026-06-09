
```C++
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m-1,j = n-1;
        int sum = m+n-1;
        while(i >= 0 && j >= 0)
        {
            if(A[i] >= B[j])
            {
                A[sum--] = A[i--];
            }
            else
            {
                A[sum--] = B[j--];
            }
        }
        
        while(i >= 0)
        {
             A[sum--] = A[i--];
        }
        
         while(j >= 0)
        {
             A[sum--] =B[j--];
        }
    }
};
```
