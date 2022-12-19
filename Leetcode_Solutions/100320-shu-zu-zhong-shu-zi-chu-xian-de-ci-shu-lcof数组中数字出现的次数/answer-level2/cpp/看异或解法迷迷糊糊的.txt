### 解题思路
不太好理解，先记着好了

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int mask = 0;
        for(auto n : nums)
        {
            mask ^= n;
        }
        int lastOne = mask & (-mask);
        int a = 0, b = 0;  //用于存储只出现一次的两个数
        for(auto n : nums)
        {
            if((n & lastOne) == 0)
                a ^= n;
            else
                b ^= n;
        }
        return {a, b};
    }
};
```