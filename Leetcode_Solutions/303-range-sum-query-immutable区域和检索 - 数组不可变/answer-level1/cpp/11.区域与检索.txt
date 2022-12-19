### 解题思路
看到题惊了不懂什么猫腻，放在dp这一块就是要用动规做啊，技巧是添加了虚拟数字0可以免去判断的条件分支，不然用i-1要判断i==0返回的情况

### 代码

```cpp
class NumArray {
     vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        int len=nums.size()+1;
        dp=vector<int>(len);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            dp[i+1]=dp[i]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```