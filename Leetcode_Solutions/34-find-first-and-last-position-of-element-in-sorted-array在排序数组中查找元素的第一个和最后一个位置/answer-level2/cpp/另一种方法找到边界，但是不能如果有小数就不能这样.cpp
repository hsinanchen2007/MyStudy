
### 代码

```cpp
class Solution {
    int Binarysearch(const vector<int>& nums,double target, bool left){
        int l = 0,r = nums.size()-1;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            if(target > nums[mid]){
                l = mid+1;
            }else{
                r = mid - 1;
            }
        }

        if(left)
            if(l >= 0 && l <nums.size() && nums[l] == target+0.5)
                return l;
            else
                return -1;
        else
            if(r >= 0 && r <nums.size() && nums[r] == (int)target)  
                return r;
            else return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {


        return {Binarysearch(nums, target-0.5,true),Binarysearch(nums, target+0.5,false)};
    }
};
```