### 解题思路

1. 前缀和
2. map保存指定前缀和出现的最后一个位置 

### 代码

```cpp
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int>  mp;
        int maxLen = 0;
        nums.insert(nums.begin(),0);
        for (int i = 1; i< nums.size(); i++){
            nums[i] += nums[i-1];
            mp[nums[i]] = i;
        }
        for (int i = 0; i< nums.size(); i++){
            if (mp.count(nums[i] + k)) {
                maxLen = max(maxLen, mp[nums[i] + k] - i);
            }
        }
        return maxLen;
    }
};
```