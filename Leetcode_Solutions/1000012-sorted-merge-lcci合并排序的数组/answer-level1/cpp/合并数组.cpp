### 解题思路

先将 A 中的元素后移 n 个单位，注意从后往前移动，然后合并即可。

### 代码

```cpp
class Solution {
   public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int i = m + n - 1, j = m - 1; j >= 0; i--, j--) {
            A[i] = A[j];
        }

        int i = n, j = 0, idx = 0;
        while (i < m + n && j < n) {
            if (A[i] < B[j]) {
                A[idx++] = A[i++];
            } else {
                A[idx++] = B[j++];
            }
        }
        while (i < m + n)  A[idx++] = A[i++];
        while (j < n) A[idx++] = B[j++];
    }
};
```