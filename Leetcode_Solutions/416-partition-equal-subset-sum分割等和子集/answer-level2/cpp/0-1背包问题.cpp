### 解题思路
可以看作是一个背包大小为sum/2的0-1背包问题
//对于背包问题而言，第j件物品，可以添加，也可以不添加;
//现在需要给背包里放的大小为sum/2;
//一个bool数组dp,大小为sum/2+1;dp[0]=1;
//dp[i]表示当放入的物体总大小为i时的值，dp[i]||dp[i-num],表示放入第j件物品之后的值
//遍历所有可以放入的物体大小


### 代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = computeArraySum(nums);
        if(sum%2!=0)
        {
            return false;
        }
        int W = sum/2; //背包大小为sum/2;
        vector<bool> dp(W+1);
        dp[0]=1;

        for(int j = 0;j<nums.size();j++)  //0-1背包问题一个物品只能用一次
        {
            int num = nums[j];
            for(int i =W;i>=num;i--) //从后往前，先计算dp[i]，再计算dp[i-num]
            {
                dp[i] = dp[i]||dp[i-num];
            }
        }
        return dp[W];

    }
private:
    int computeArraySum(vector<int> &nums) //得到数组的总和
    {
        int sum = 0;
        for(int num = 0;num<nums.size();num++)
        {
            sum+=nums[num];
        }
        return sum;
    }
};
```