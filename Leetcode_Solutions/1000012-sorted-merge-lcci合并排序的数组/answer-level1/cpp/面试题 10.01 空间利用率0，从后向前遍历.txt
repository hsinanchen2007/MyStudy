### 解题思路
空间占用0，时间复杂度O(n)；
从后向前遍历A和B，利用m和n作为遍历索引。

### 代码
```cpp
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int i=m+n-1; i>=0; i--) {
            if (m && n) {
                if (A[m-1] > B[n-1]) {
                    A[i] = A[m-1];
                    m--;
                } else {
                    A[i] = B[n-1];
                    n--;
                }
            } else if (m) {
                A[i] = A[m-1];
                m--;
            } else {
                A[i] = B[n-1];
                n--;
            }            
        }
    }
};
```
