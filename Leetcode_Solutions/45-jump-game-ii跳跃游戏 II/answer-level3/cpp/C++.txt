### 解题思路
对于其中某一步来说，需要知道当前能达到的最远距离，然后在当前位置和最远距离中间的位置，是否还存在可以到达比目前最远距离还远的位置，需要一直更新最远距离。

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        if (nums.size() == 0)
            return steps;
        int farest = 0;
        int right = 0;
        for (int i=0; i<nums.size()-1; ++i)
        {
            farest = (i+nums[i]) > farest ? (i+nums[i]):farest;
            if (i == right)
            {
                steps++;
                right = farest;
            }
        }
        return steps;
    }
};
```