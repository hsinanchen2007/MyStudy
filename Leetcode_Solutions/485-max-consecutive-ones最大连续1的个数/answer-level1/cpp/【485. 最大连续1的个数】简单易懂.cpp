## 思路
### 代码
```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, c = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 1) {
                res = max(res, c);
                c = 0;
            } else {
                ++c;
            }            
        }
        res = max(res, c);
        return res;
    }
};
```
