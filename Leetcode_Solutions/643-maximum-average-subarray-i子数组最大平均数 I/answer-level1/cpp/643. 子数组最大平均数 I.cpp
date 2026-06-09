## 先找出连续k个数的最大和
```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size(), sum=0;
        double ans;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        int maxSum = sum;
        for(int i=k; i<len; i++){
            sum = sum-nums[i-k]+nums[i];
            maxSum = maxSum > sum ? maxSum : sum;
        }
        ans = (double)maxSum / k;
        return ans;
    }
};
```