### 解题思路
贪心算法，所谓骑驴找马，关键是要保护好自己的驴，不能碰见骡子反而把自己的驴给丢了，碰见比自己好的马才行

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=nums[i];
            maxs=max(count,maxs);
            if(count<0) count=0;
        }
        return maxs;
    }
};
```