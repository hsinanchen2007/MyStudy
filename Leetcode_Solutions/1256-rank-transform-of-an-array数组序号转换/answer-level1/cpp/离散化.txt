离散化的板子
```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = lower_bound(arr.begin(),arr.end(),nums[i]) - arr.begin() +  1;
        }
        return nums;
    }
};
```