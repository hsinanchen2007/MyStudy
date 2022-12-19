### 解题思路
用map来记录已经出现过的数的个数，但个数大于n/2就可以直接返回结果了

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int len = nums.size();
        int half_len = len / 2;
        int i;
        for (i=0; i<len; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > half_len) break;
        }
        return nums[i];
    }
};
```