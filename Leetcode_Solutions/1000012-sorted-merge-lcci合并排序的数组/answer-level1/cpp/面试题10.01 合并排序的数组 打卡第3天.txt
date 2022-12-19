三指针（或者说归并排序） 从后向前填充A向量
A向量的后侧提前预留出了B向量的空间，就算B向量全部填充进去也不会损失A中原有的元素
```c++
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx = m + n - 1; int idx_a = m - 1; int idx_b = n - 1;
        while(idx_b >= 0){
            if(idx_a >= 0 && A[idx_a] > B[idx_b]) A[idx--] = A[idx_a--];
            if(idx_a < 0 || B[idx_b] >= A[idx_a]) A[idx--] = B[idx_b--];
        }
    }
};
```