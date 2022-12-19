### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums[0] == 0) 
            if (nums.size() == 1) return true;
            else return false;
        int pos = nums.size()-1,del = 0;
        while (pos > 0) {
            while (nums[--pos] - (++del) < 0) 
                if (pos == 0) return false;
            del = 0;
        }
        return true;
    }
};
```