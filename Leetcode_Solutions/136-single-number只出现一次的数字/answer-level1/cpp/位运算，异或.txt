### 解题思路
题目说每个重复的数只出现两次，所以异或得零，最终就剩下一个要找的数
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret=0;
        for(auto num:nums)
        ret=ret^num;
        return ret;
    }
};
```