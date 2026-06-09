### 解题思路
如果没有平均值，可以直接利用滑窗求出最小值；
求最大的平均值，可以利用将所有的数减去某个数，如果能够找到一段子序列和大于0，就证明这段子序列的平均值大于某个数；
至于找某个数的过程可以使用二分查找的思想，快速逼近结果。

### 代码

```cpp
class Solution {
public:
    bool IsNumsBigger(vector<int>& nums, int k, double ans) {
        vector<double> preSums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            preSums[i+1] = preSums[i] + nums[i] - ans;
        }
        double minVal = 0;
        for (int i = k; i < preSums.size(); i++) {
            minVal = min(preSums[i-k], minVal);
            if (preSums[i] - minVal >= 0) {
                return true;
            }
        }
        return false;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        
        double leftValue =-10000;
        double rightValue = 10000;
        double ans = (leftValue+rightValue)/2;
        while( rightValue - leftValue > 10e-6) {
            if (IsNumsBigger(nums, k, ans)) {
                leftValue = ans;
            } else {
                rightValue = ans;
            }
            ans = (leftValue + rightValue)/2;
            
        }
        return ans;
    }
};
```