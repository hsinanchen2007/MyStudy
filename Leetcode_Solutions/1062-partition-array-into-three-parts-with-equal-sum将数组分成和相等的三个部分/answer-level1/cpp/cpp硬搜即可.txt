### 解题思路
直接找是否存在两个断点即可

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if (A.size() < 3) return false;
        int i, j, prefix_sum = 0, sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) return false;
        for (i = 0; i < A.size(); i ++) {
            prefix_sum += A[i];
            if (prefix_sum  == sum / 3) break;
        }
        for (j = i + 1; j < A.size(); j ++) {
            prefix_sum += A[j];
            if (prefix_sum == sum / 3 * 2) break;
        }
        if (i == A.size() || j == A.size() || j == A.size() - 1) return false;
        return true;
    }
};
```