### 解题思路
注意到数字大小为[0, 100]，直接用一个101大小的数组在遍历一遍的过程中存储每个数字的个数就可以了，然后再加一次，按序去除就是结果

### 代码

```cpp
class Solution {
#define Max 101
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[Max], cal[Max];
        memset(cnt, 0, sizeof cnt);
        for(auto num : nums)
            ++cnt[num];
        cal[0] = 0;
        for(size_t idx = 1; idx < Max; ++idx)
            cal[idx] = cal[idx-1] + cnt[idx-1];
        vector<int> rslt;
        for(auto num : nums)
            rslt.push_back(cal[num]);
        return rslt;
    }
};
```