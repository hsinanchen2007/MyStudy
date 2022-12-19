### 解题思路
注意：先判断计算再跳过相同元素
重复元素的处理

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3){
            return res;
        }
        for(int k = 0; k < nums.size()-2; k++){
            int i = k + 1, j = nums.size() - 1;
            if(nums[k] > 0) break;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                if(nums[j] < 0) break;
                if(sum == 0){
                    vector<int> tmp;
                    tmp.push_back(nums[k]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    res.push_back(tmp);
                    j--;
                    while(nums[j] == nums[j+1] && i < j) j--;
                    i++;
                    while(nums[i] == nums[i-1] && i < j) i++;
                }
                else if(sum > 0){
                    j--;
                    while(nums[j] == nums[j+1] && i < j) j--;
                }
                else if(sum < 0){
                    i++;
                    while(nums[i] == nums[i-1] && i < j) i++;
                }
            }
            while(nums[k] == nums[k+1] && k < nums.size()-2) k++;
        }
        return res;
    }
};
```