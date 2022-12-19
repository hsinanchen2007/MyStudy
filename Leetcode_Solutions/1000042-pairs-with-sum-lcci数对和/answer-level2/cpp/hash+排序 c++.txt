### 解题思路
此处撰写解题思路

### 代码

排序 O(nlogn)时间, O(1)空间
```
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) res.push_back({nums[i ++], nums[j --]});
            else if (sum < target) i ++;
            else j --;
        }
        return res;
    }
};
```
hash O(n)时间 O(n)空间
```
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        // O(n)
        unordered_map<int, int> hash;
        vector<vector<int>> res;
        for (auto x: nums) {
            int diff = target - x;
            if (hash.count(diff) && hash[diff]) res.push_back({x, diff}), hash[diff] --;
            else hash[x] ++;
        }
        return res;
    }
};
```
