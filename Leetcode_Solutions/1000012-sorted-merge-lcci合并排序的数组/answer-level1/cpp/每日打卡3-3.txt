### 解题思路
从后往前排，三行代码搞定

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int index = m + n;
        while (m > 0 && n > 0) A[--index] = A[m - 1] > B[n - 1] ? A[--m] : B[--n];
        while (n > 0) A[--index] = B[--n];
    }
};
```