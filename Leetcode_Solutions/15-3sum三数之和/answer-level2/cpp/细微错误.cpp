### 解题思路
代码是参考别人的写出来的，但是参考过程中遇到了一个很细微的差别，就是在下面的代码中
                    ++j,--k;
                    while(j < k && nums[j] == nums[j - 1]) ++j;
                    while(j < k && nums[k] == nums[k + 1]) --k;
起初我是写这样：
                    ++j,--k;
                    while(j < k && nums[j] == nums[j + 1]) ++j;
                    while(j < k && nums[k] == nums[k - 1]) --k;
区别就在于while循环判断，而后果就是总是会漏掉一些情况，我想是因为每次j、k都多移一次，从而导致跳过一些可能的答案。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> ans_set;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = size - 1; j < k;){
                if(nums[j] + nums[k] == 0 - nums[i]){
                    ans_set.push_back({nums[i], nums[j], nums[k]});
                    ++j,--k;
                    while(j < k && nums[j] == nums[j - 1])
                        ++j;
                    while(j < k && nums[k] == nums[k + 1])
                        --k;
                }
                else if(nums[j] + nums[k] > 0 - nums[i])
                    --k;
                else
                    ++j;
            }
            
        }
        return ans_set;
    }
};
```