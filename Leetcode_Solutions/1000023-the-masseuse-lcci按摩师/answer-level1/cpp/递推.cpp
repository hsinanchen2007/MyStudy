

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int ppre = 0, pre = 0, now = 0;
        for(int i=1, n=nums.size(); i<=n;i++)
        {
            ppre = pre;
            pre = now;
            now = max(pre, ppre+nums[i-1]);
        }
        return now;
    }
};
```