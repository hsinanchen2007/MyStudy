### 解题思路
1. 可以明确知道的是扑克牌中假如出现同样的牌，就不可能组成顺子。
2. 如果牌中数字出现跳跃，那么要看牌中的大小王（数字0）能否填补这个跳跃，比如`[0, 0, 1, 2, 5]`。出现的跳跃0刚好可以填补

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //统计0的个数
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i){
            if(nums[i] == 0) cnt ++;
            else if(nums[i] == nums[i+1]) return false;
            //产生的跳跃
            else if(nums[i] + 1 != nums[i+1]){
                cnt -= (nums[i+1] - nums[i] - 1);
            }
        }
        return cnt >= 0;
    }
};
```