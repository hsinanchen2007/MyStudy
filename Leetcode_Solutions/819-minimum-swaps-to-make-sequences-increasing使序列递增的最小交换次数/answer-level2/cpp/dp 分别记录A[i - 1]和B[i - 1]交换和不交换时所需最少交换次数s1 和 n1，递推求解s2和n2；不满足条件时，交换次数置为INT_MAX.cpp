### 解题思路
A[i] 与 B[i] 是否交换取决与A[i - 1] 和 B[i - 1]是否交换

### 代码

```cpp
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        // 这两组序列该满足条件：
        // max(A[i + 1], B[i + 1]) > max(A[i], B[i])
        // min(A[i + 1], B[i + 1]) > min(A[i], B[i])
        int len = A.size();
        int n1 = 0; // not swap
        int s1 = 1; // swap
        for (int i = 1; i < len; i++) {
            int n2 = INT_MAX;
            int s2 = INT_MAX;
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                n2 = min(n2, n1);
                s2 = min(s1 + 1, s2);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                n2 = min(n2, s1);
                s2 = min(n1 + 1, s2);
            }
            n1 = n2;
            s1 = s2;
        }
        return min(n1, s1);
    }
};
```