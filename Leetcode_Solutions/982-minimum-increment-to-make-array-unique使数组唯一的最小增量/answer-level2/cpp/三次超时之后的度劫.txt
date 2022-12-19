### 解题思路
献给超时的耿直boy。
``` c++
int minIncrementForUniqueTimeoutVersion(vector<int> &A) {
    int len = A.size();
    int ans = 0;
    sort(A.begin(), A.end());
    for (int i = 1; i < len; ++i) {
        while (A[i] <= A[i - 1]) {
            A[i]++;
            ans++;
        }
    }
    return ans;
}
```


### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int len = A.size();
        int ans = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < len; ++i) {
            int pre = A[i - 1];
            if (A[i] <= pre) {
                int tmp = A[i];
                A[i] = pre + 1;
                ans += pre + 1 - tmp;
            }
        }
        return ans;
    }
};
```