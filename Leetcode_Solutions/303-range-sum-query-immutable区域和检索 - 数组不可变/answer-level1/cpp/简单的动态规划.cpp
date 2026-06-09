### 解题思路
思路很简单，我们用一个数组dp[]截至到s[k]的累加和，当求i-j的累加和时 可以用dp[j]=dp[i-1]求得

### 代码

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) {
       dp=vector<int>(nums.size()+1,0);
       if(nums.empty())
       {
           return;
       }
       dp[0]=nums[0];
       for(int i=1;i<=nums.size();i++)
       {
           dp[i]=dp[i-1]+nums[i-1];
       }
    }
    
    int sumRange(int i, int j) {
          return dp[j+1]-dp[i];
    }
    vector<int>dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```