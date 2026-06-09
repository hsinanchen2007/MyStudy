### 解题思路
此处撰写解题思路

### 代码

```cpp
//C++:记忆化搜索
vector<vector<int>> memo;
// memo[index]:用 [0...index]的物品,能否将容积为c的背包填充满
bool tryPartition(vector<int>& nums, int index, int c) {

    if(index < 0 || c < 0) {
        return false;
    }
    if(c == 0)
        return true;

    if(memo[index][c] != -1) {
        return memo[index][c] == 1;
    }
    
    memo[index][c] = (tryPartition(nums, index-1, c)
                    || tryPartition(nums, index - 1, c - nums[index])) ? 1 : 0;  
    
    return memo[index][c] == 1;    

}
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return true;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    memo = vector<vector<int>>(n, vector<int>(sum/2 + 1, -1));
    return tryPartition(nums, n-1, sum/2);
}
//动态规划：
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return true;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    int c = sum/2;
    vector<bool> memo(c + 1, false);
    for(int i = 0; i <= c; i++) {
        memo[i] = (nums[0] == i);
    }

    for(int i = 1; i < n; i++) {
        //求解memo[i]
        for (int j = c; j >= nums[i]; j--) {
            memo[j] = (memo[j] || memo[j-nums[i]]);
        }
    }
    return memo[c];
}
```