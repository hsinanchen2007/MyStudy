
### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(target >= nums[0])
            for(int i=0; i<nums.size();++i){
                if(nums[i]==target)
                    return true;
                if(i>0 && nums[i-1] > nums[i])
                    break;
            }
        else if(target <= nums[nums.size()-1])
            for(int i=nums.size()-1; i>0; --i){
                if(nums[i]==target)
                    return true;
                if(nums[i]<nums[i-1])
                    break;
            }
        return false;
    }

};
```