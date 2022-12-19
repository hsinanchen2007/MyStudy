### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for (int i = 1; i < A.size(); i ++ ) {
            if (A[i] <= A[i - 1]) {
                
                res += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};
```