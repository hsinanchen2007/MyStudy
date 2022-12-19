### 解题思路

在最长升序子序列问题中, 设序列长度为n, 最长升序子序列长度为m

未优化的时间复杂度: $O(n*m)$

已优化的时间复杂度: $O(n\log{m})$

空间复杂度: $O(m)$

当m=3时, `m`为常数

此时, 时间复杂度:$O(n)$, 空间复杂度:$O(1)$

### 代码

```
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        int dp[3];
        memset(dp, 0x7F, sizeof dp);
        
        for (int num : nums) {
            for (int i = 0; i < 3; ++i) {
                if (dp[i] < num) continue;
                if (i == 2) return true;
                dp[i] = num;
                break;
            }
        }
        
        return false;
    }
};
```