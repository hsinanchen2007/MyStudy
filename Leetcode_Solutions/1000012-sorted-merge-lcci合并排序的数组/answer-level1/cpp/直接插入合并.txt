直接找位置插入就好了
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        // 线性走一趟就可以了
        if (n == 0) return;
        int A_curr = 0;
        for (int i = 0; i < n; i++)
        {
            while (B[i] > A[A_curr] && A_curr < m)
            {
                A_curr++;
            }
            // 这个时候A_curr就是B[i]要插入的位置，这个时候A_curr及后面的元素往后移
            for (int j = m; j > A_curr; j--)
            {
                A[j] = A[j - 1];
            }
            A[A_curr] = B[i];
            m++;
        }
        return;
    }
};
```
