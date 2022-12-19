![捕获.PNG](https://pic.leetcode-cn.com/e1b55c97c3c200475606ff8a7131412945bcd5ab08d01d54ad038e39f121fbc2-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if (n <= 0)
            return;
        
        int ap = 0;
        while (ap < m) {
            if (B[0] < A[ap]) {
                int tmp = A[ap];
                A[ap] = B[0];
                int i;
                for (i = 1; i < n; ++i) {
                    if (tmp < B[i]) {
                        B[i - 1] = tmp;
                        break;
                    } else {
                        B[i - 1] = B[i];
                    }
                }
                if (i == n) {
                    B[n - 1] = tmp;
                }
            }
            ap++;
        }
        for (int i = 0; i < n; ++i) {
            A[ap++] = B[i];
        }
    }
};
```
