### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int max_value = *max_element(A.begin(), A.end());
        int min_vlaue = *min_element(A.begin(), A.end());

        if (max_value - min_vlaue - 2*K < 0) return 0;

        return max_value - min_vlaue - 2*K;
    }
};
```