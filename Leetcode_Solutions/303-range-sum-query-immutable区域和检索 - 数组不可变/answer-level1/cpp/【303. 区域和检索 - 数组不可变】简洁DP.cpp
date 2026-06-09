### 思路


### 代码

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) {        
        if (!nums.empty()) {
            dp = nums;            
            for (int i = 1; i < nums.size(); ++i) {
                dp[i] += dp[i - 1];
            }
        }        
    }
    
    int sumRange(int i, int j) {
        return dp[j] - (i > 0 ? dp[i - 1] : 0);//注意判断i
    }
private:    
    vector<int> dp;
};
```