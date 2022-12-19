```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            if (!mp.count(nums[i])){
                mp.insert(pair<int, int>(nums[i], i));
            }
            else{
                if (i - mp[nums[i]] <= k)
                    return true;
                else//更新value值，可能后面会出现符合要求的两个不同索引，如[1,0,1,1] 1,符合要求的为后两个1(3 - 2 <= 1)。
                    mp[nums[i]] = i; 
            }
        }
        return false;
    }
};
```
