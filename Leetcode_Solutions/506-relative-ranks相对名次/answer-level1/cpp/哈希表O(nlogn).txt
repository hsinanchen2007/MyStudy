### 解题思路
O(n)额外空间，主要就是个哈希表。自己基础不太牢扎，刚刚才知道size()函数返回的是无符号数。。。崩溃

### 代码

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> re(nums.size(), "0");
        for (int i=0; i<nums.size(); i++) {
            mp.insert(pair<int, int>(nums.at(i), i));
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int i=0; i<(int)nums.size()-3; i++) {
            re.at(mp.find(nums.at(i))->second) = to_string(nums.size()-i);
        }
        if (nums.size() >= 3)        
            re.at(mp.find(nums_s[nums.size()-3])->second) = "Bronze Medal";
        if (nums.size() >= 2)
            re.at(mp.find(nums_s[nums.size()-2])->second) = "Silver Medal";
        if (nums.size() >= 1)
            re.at(mp.find(nums_s[nums.size()-1])->second) = "Gold Medal";            
        return re;
    }
};
```