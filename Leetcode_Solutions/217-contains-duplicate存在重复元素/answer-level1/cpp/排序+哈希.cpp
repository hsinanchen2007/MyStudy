```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 哈希
        unordered_set<int> s;
        for(const int &x: nums){
            if(s.count(x) > 0)
                return true;
            s.insert(x);
        }
        return false;

        // 排序
        // if(nums.empty()) return false;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size() - 1; ++i)
        //     if(nums[i] == nums[i+1])
        //         return true;
        // return false;
    }
};
```
