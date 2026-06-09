### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1;
        int pb = n - 1;
        int tail = m + n - 1;
        int cur;
        while (pa >= 0 || pb >= 0)
        {
            if (pa == -1)
            {
                cur = B[pb--];
            }
            else if (pb == -1)
            {
                cur = A[pa--];
            }
            else if (A[pa] > B[pb])
            {
                cur = A[pa--];
            }
            else
            {
                cur = B[pb--];
            }
            A[tail--] = cur;
        }
    }
};
```