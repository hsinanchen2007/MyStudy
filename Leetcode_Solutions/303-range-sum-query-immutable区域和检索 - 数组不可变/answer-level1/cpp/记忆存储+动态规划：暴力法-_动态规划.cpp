# 1. 暴力法：
- 建立NxN的表，行代表i，列代表j。
- dp[i][j]表示，从数组i元素到j元素的和。
- 第一行代表dp[0][j]表示从数组第一个元素加到j元素。
- 从左上角到右下角画一条对角线（i=j）。对角线dp[i][j] = nums[j];
```
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        if(n>0) {
            vector<vector<int>> dp(n);
            for (int i=0; i<n; ++i)
                dp[i].resize(n);
            dp[0][0] = nums[0];
            for(int x=1; x<n; ++x) {
                dp[0][x] = dp[0][x-1] + nums[x];
                for(int y=1; y<=x; ++y) {
                    dp[y][x] = dp[y-1][x] - nums[y-1];
                }
            }

            res.swap(dp);
        }
    }
    
    int sumRange(int i, int j) {

        return res[i][j];
    }
private:
    vector<vector<int>> res;
};
```
需要计算右上角所有值并存储，空间复杂度O(N^2)，时间复杂度过高O(N^2)，超时。
# 2. 动态规划
- 我们不直接存储结果，我们存储从第一个元素到第i个元素的和dp[i] = sum(nums[0]~nums[i-1]);
- 动态转移方程：
dp[i] = dp[i-1] + nums[i-1];
res = dp[j+1] - dp[i];
- 初始条件
dp[0] = 0
- dp尺寸为N+1
因为你要保证i=j的时候不会return 0 , 而应该return nums[j]，所以dp的尺寸应该为N+1，result[i][j] = dp[j+1] - dp[i]。换句话说当i=0, j=0时，result[0][0] = dp[1] - dp[0] = nums[0];
```
class NumArray {
public:
     NumArray(vector<int>& nums) {
        int n = nums.size();
        if(n>0) {
            vector<int> dp(n+1);
            dp[0] = 0;
            for(int i=1; i<=n; ++i)
                dp[i] = dp[i-1] + nums[i-1];
            res.swap(dp);
        }
    }
    
    int sumRange(int i, int j) {

        return res[j+1]-res[i];
    }
private:
    vector<int> res;
};
```
时间复杂度O（N）空间复杂度O(N)