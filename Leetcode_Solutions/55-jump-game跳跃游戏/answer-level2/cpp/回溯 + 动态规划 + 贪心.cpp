## 回溯法
```C++ []
class Solution {
public:
    bool backtrack(int p, vector<int>& nums){
        if(p == nums.size() - 1)
            return true;
        int jump = (nums[p] + p) < (nums.size() - 1)? nums[p] + p: nums.size() - 1;
        
        for(int i = jump; i > p; i--){
            if(backtrack(i, nums))
                return true;
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        return backtrack(0, nums);
    }
};

```
很可惜，回溯法，超时了。

## 自顶向下的动态规划
```C++ []
class Solution {
public:
    bool jump(vector<int>& dp, int p, vector<int>& nums){
        if(dp[p])
            return dp[p] == 1? true: false;
        int j = (p + nums[p]) < (nums.size() - 1)? p + nums[p]: nums.size() - 1;
        for(int i = p + 1; i <= j; ++i)
            if(jump(dp, i, nums)){
                dp[i] = 1;
                return true;
            }
        dp[p] = -1;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 1;
        return jump(dp, 0, nums);
    }
};

```
基本就是按照回溯来的。很可惜，也超时了。

## 自底向上的动态规划
```C++ []
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 1;
        
        for(int i = nums.size() - 2; i >= 0; i--){
            int jump = (i + nums[i]) < (nums.size() -1)? i + nums[i]: nums.size() - 1;
            for(int j = i + 1; j <= jump; j++){
                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};

```
执行用时 :
1116 ms
, 在所有 C++ 提交中击败了
5.01%
的用户
内存消耗 :
10.2 MB
, 在所有 C++ 提交中击败了
40.50%
的用户

虽然没有超时，但是依然慢的不行。

## 贪心算法
```C++ []

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = n - 1;
        for(int i = n - 1; i >= 0; --i){
            if(i + nums[i] >= last){
                last = i;
            }
        }
        return !last;
    }
};
```
