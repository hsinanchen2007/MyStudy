![2.png](https://pic.leetcode-cn.com/2e30566db366c5b2a5121417aac85a6ecfe0b2301beb694cfb020fe6a1e81489-2.png)

### 代码
```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i = 0, j = 1; i < A.size(); i += 2) {
            if (A[i] & 1) {
                while (A[j] & 1)j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};
```