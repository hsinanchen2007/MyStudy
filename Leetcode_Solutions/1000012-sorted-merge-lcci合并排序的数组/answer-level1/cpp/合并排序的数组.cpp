### 解题思路

更为简洁的双指针

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1, pb = n - 1;
        int res = m + n -1;
        int cur;
        while(pb >= 0)
        {
            A[res--] = (pa>=0&&A[pa] >= B[pb]?A[pa--]:B[pb--]);
        }
    }
};
```