### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return res;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] > nums[i-1]){
                for(int j = i + 1; j < nums.size(); j++){
                    if(j == i + 1 || nums[j] > nums[j-1]){
                        int left = j + 1, right = nums.size() - 1;
                        while(left < right){
                            int s = nums[i] + nums[j] + nums[left] + nums[right];
                            if(s == target){
                                res.push_back({nums[i], nums[j], nums[left], nums[right]});
                                left++; right--;
                                while(left < right && nums[left] == nums[left-1]){
                                    left++;
                                }
                                while(left < right && nums[right] == nums[right+1]){
                                    right--;
                                }
                            }else if(s < target){
                                left++;
                            }else{
                                right--;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
```