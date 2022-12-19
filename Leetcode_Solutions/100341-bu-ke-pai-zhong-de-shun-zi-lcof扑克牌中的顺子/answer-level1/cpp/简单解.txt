### 解题思路
代码即思路,判断两个数之间的slot与万用牌的数量

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int slot = 0;
        int zeroCnt = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == 0) {
                ++zeroCnt; 
                continue;
            }
            int t = nums[i+1] - nums[i];
            if (t == 0) {
                return false;
            }
            if (t > 1) {
                slot += t - 1;
            }
        }

        return slot > 0 ? slot <= zeroCnt : true;
    }
};
```