嘛算是挺偷懒的...
```
class Solution {
public:
    bool containsDuplicate(vector<int> nums) {
        int pre_size = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size() != pre_size;
    }
};
```
