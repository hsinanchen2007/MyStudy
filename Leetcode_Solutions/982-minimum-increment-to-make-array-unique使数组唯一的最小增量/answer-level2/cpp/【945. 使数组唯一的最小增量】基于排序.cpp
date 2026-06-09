## 思路
先排序，然后从头开始，每次遇到相同数，则递增1，如果当前数小于前一个数，则当前数递增到前一个数加1。

### 代码
时间复杂度：O(nlogn)，排序时间复杂度
空间复杂度：O(logn)
```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) {
                ++A[i];
                ++res;
            } else if(A[i] < A[i - 1]) {
                res += A[i - 1] + 1 - A[i]; 
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};
```