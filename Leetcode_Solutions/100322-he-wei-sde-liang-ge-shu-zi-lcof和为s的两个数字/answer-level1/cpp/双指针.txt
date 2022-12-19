### 解题思路
双指针，经典的两数之和

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                return res;
            }
            else
                if(nums[i]+nums[j]<target)
                    i++;
                else
                    j--;
        }
        return res;
    }
};
```