### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return A;
        int R = A.size();
        int C = A[0].size();
        for (int i = 0; i < R; ++i) {
            int l = 0;
            int r = C - 1;
            while (l < r) {
                swap(A[i][l], A[i][r]);
                A[i][l++] ^= 1;
                A[i][r--] ^= 1;
            }
            if (C & 1) A[i][C >> 1] ^= 1;
        }
        return A;
    }
};
```

![image.png](https://pic.leetcode-cn.com/8aded842a8846d388103617ab2ed47f94e4eb674685915de288adb399e0043ca-image.png)
