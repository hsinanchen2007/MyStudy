1. 时间复杂度O(n), 空间复杂度O(n)
```C++ []
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        map<int, int> times;
        for(int i=0; i<nums.size(); i++)
        {
            if(!times.count(nums[i]))
                times[nums[i]]++;
            else
                return true;
        }
        return false;
    }
};
```

