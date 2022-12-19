### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size < 1) {
            return 0;
        }
        int ppre = 0; int pre = nums[0];
        
        for (int i = 1; i < size; i++) {
            int tmp = ppre;
            ppre = pre;
            pre = max(tmp + nums[i], pre);
        }

        return max(ppre, pre);
    }
};
```