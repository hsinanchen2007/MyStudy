### 解题思路
利用map存储每个数字出现的次数，进而判断

### 代码

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()<=1) return 0;

        map<int,int> count;
        for(auto num:nums)
        count[num]++;

        int max=0;
        for(auto c:count)
        if(count.count(c.first+1)&&max<c.second+count[c.first+1])
        max=c.second+count[c.first+1];

        return max;

    }
};
```