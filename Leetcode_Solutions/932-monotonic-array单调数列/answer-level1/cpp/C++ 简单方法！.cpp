### 解题思路
见注释。

### 代码

```cpp
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 1)
            return true;

        int a = 0;
        int b = 0;

        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] < A[i + 1]) a = 1;
            if (A[i] > A[i + 1]) b = 1;
        }

        // 如果数组不单调，则 a = 1, b = 1，否则 a 和 b 只有一个为 1
        if (a + b == 2)
            return false;
        else
            return true;
    }
};
```