
### 代码

```cpp
class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums):nums(nums) {
        
    }
    
    int pick(int target) {
        vector<int> help;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==target) help.push_back(i);
        int n=help.size();
        int index=rand()%n;
        return help[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
```