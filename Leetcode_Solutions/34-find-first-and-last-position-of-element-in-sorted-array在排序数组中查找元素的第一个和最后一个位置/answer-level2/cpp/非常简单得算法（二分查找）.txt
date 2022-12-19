### 解题思路
先用二分查找目标是否在数组中，若在，同时获得所在得一个位置

从当前位置向两边查找，确定上下界

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
       if(nums.empty())
        return ans; 
    int pos=0;
    if (ifhave(nums,target,pos)){
        ans.pop_back();
        ans.pop_back();
        int pos_lo=pos;
        int pos_hi=pos;
        while( pos_lo>=0 && nums[pos_lo]==target)
            --pos_lo;
        ans.push_back(pos_lo+1);
        while(pos_hi<nums.size() && nums[pos_hi]==target)
            ++pos_hi;
        ans.push_back(pos_hi-1);
        return ans;
    }
    else
        return ans;
    }
    bool ifhave(vector<int>& nums,int& target,int& pos){
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            pos=(lo+hi)/2;
            if(nums[pos]==target)
                return true;
            if(nums[pos]<target)
                lo=pos+1;
            else
                hi=pos-1;
        }
        return false;
    }
};
```