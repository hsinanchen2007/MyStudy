### 解题思路
记录最远点

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farPoint = 0; // 能跳到的最远点
        for(int i=0;i<nums.size();i++){ //
            if(farPoint < i)    return false;
            else if(i + nums[i] > farPoint)
                farPoint = i + nums[i];
        }
        return true;
    }
};
```