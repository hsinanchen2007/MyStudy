### 解题思路
利用数组的已排序性质，依次从数组后面选择较大的数字放到A数组的右侧。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1;
        int j = n - 1;
        int backIdx = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[backIdx--] = A[i--];
            } else {
                A[backIdx--] = B[j--];
            }
        }
        while (j >= 0) {
            A[backIdx--] = B[j--];
        }
    }
};
```