### 解题思路
关键点在等于nums等于0的位置，如果之前所有的点所能达到的最大距离无法超过0的位置，那么必然不可以到达终点

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp = 0;
        for(int i=0; i<nums.size(); i++){
            if(i<=dp){
                dp = max(dp, i+nums[i]);
                if(dp > nums.size()) return true;
            }
            else return false;
        }
        return true;
    }
};
```