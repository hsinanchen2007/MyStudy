只需要依次将**A数组最后一个元素**和**B数组最后一个元素**两个数中**较大**的那个复制到**A末端**即可。
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(A[i]>B[j])
            A[k--]=A[i--];
            else
            A[k--]=B[j--];
        }
        while(i>=0)
            A[k--]=A[i--];
        while(j>=0)
            A[k--]=B[j--];

    }
};
```
