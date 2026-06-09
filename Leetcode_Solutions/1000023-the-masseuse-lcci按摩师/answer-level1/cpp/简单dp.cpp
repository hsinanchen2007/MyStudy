### 解题思路
dp[n] = max(dp[n-1], dp[n-2] + cur)
// dp[n] 表示前n项的最大值

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int pre = 0, cur = 0, tmp = 0;  // pre indicates can pick current num,
                                        // cur indicates can't pick current num
        for(int num : nums){
            tmp = max(pre + num, cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};
```