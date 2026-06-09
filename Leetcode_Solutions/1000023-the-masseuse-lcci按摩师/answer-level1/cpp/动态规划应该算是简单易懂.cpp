dp存的是当前节点的最大值
针对于第i个位置 选择它的只能是i-2或者i-3位置的值，
如果小于i-3（即跳过3个数去选择下一个值）则会少一个选取的值导致不可能得到最大值。
所以状态转换方程就像这样：
```
dp[i] = max(dp[i-2],dp[i-3]) + nums[i];
```
下面是完整代码

```
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int massage(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        int m = 0;
        for(int i =0;i<dp.size();i++)
        {
            if(i<2)
            {
                dp[i]=nums[i];
            }
            else if(i==2)
            {
                dp[i] = nums[0]+nums[2];
            }
            else
            {
                dp[i] = max(dp[i-2],dp[i-3]) + nums[i];
            }
            m = m>dp[i]?m:dp[i];
        }
        return m;
    }
};
```
