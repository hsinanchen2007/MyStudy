### i
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> uset;
        for (const int &num: nums) {
            auto res = uset.insert(num);
            if (!res.second) return num;
        }
        return 0;
    }
};
```
### ii
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) return nums[i];
                else swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};
```