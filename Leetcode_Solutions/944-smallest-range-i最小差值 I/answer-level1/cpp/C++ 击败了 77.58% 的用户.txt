![1.png](https://pic.leetcode-cn.com/9906679456418ab82a58677a14a2813634e91dd40dc322cd3b6439e4773195e8-1.png)

### 代码
```cpp
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxValue = *max_element(A.begin(),A.end());
        int minValue = *min_element(A.begin(),A.end());

        return max(0, maxValue - minValue - 2*K);
    }
};
```