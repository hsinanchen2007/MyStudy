### 解题思路
利用等差数列求和公式求1+2+...+n再与nums元素之和相减，全部放在return语句里

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        return ((1 + nums.size()) * nums.size()) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
```