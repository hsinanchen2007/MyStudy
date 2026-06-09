
### 解题思路
回溯
![e2042f39fb03171ea6321420b3f9644.jpg](https://pic.leetcode-cn.com/7fd051374925c3ce1219400add845a75de79080924f6f2dc7804849264efaa85-e2042f39fb03171ea6321420b3f9644.jpg)

### 代码

```cpp
class Solution {
public:
//backTrack：提取第i个数所获得的coins.
    int maxCoins(vector<int>& nums) {
        int coin = 0;
        maxCoin = 0;
        backTrack(nums, coin);
        return maxCoin;
    }
private:
    void backTrack(vector<int>& nums, int& coin){
        if(nums.empty()){
            maxCoin = max(maxCoin, coin);
            return;
}
        for(int i = 0; i < nums.size(); i++){
            int tempI = nums[i];
            int tempCoin = nums[i] * (i - 1 < 0 ? 1 : nums[i-1]) * (i + 1 >= nums.size() ? 1 : nums[i+1]);
            coin += tempCoin;
            nums.erase(nums.begin() + i);
            backTrack(nums, coin);
            nums.insert(nums.begin() + i, tempI);
            coin -= tempCoin;
        }
        return;
    }
    int maxCoin;
};
```


### 解题思路
递归+记忆化
![捕获.PNG](https://pic.leetcode-cn.com/0089a2f4c3cd12456726516e5a70d36eb00a07cda761411f1cfda108071a4005-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    //递归+记忆化
    //memo[i][j]: 打爆范围为[i,j]的气球所获得的最大coins.
    //memo[i][j] = nums[i-1]*nums[k]*nums[j+1] + memo[i][k-1] + memo[k+1][j];
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        maxCoin(nums, 1, nums.size() - 2, memo);
        return memo[1][nums.size() - 2];
    }
private:
    int maxCoin(vector<int>& nums, int l, int r, vector<vector<int>>& memo) {
        if(memo[l][r] != 0){
            return memo[l][r];
        }
        if(l > r){
            return 0;
        }
        if(l == r){
            memo[l][r] = nums[l-1]*nums[l]*nums[l+1];
            return memo[l][r];
        }
        for(int k = l; k <= r; k++){
            int add = nums[k] * nums[l-1] * nums[r+1];
            memo[l][r] = max(memo[l][r], maxCoin(nums, l, k-1, memo) + maxCoin(nums, k+1, r, memo) + add);
        }
        return memo[l][r];
    }
};
```


### 解题思路
DP

### 代码

```cpp
class Solution {
public:
    //动态规划
    //dp[i][j]: 打爆范围为[i,j]的气球所获得的最大coins.
    //dp[i][j] = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for(int l = 1; l <= nums.size() - 2; l++){
            for(int i = 1; i < nums.size() - l; i++){
                int j = i + l - 1;
                for(int k = i; k <= j; k++){
                    int add = nums[k] * nums[i-1] * nums[j+1];
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + add);
                }
            }
        }
        return dp[1][nums.size() - 2];
    }
};
```