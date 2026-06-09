### 解题思路
hash表

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> res(100000, 0);
        for (auto num : nums) {
            res[num]++;
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] > 1) {
                return i;
            }
        }
        return 0;
    }
};
```