### 解题思路
数组、字符串问题均可以想到以每一个元素结尾的问题，本问题就是任意一个元素nums[j]结尾的最大累乘积，可能来源有以下三种：
1.之前nums[j-1]结尾的最大累乘积*nums[j]
2.之前nums[j-1]结尾的最小累乘积*nums[j]
3.只有nums[j]

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<1)
        return 0;
        int minend=0;
        int maxend=0;
        int res=nums[0];
        int minvalue=nums[0];
        int maxvalue=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            minend=minvalue*nums[i];
            maxend=maxvalue*nums[i];
            minvalue=min(nums[i],min(maxend,minend));
            maxvalue=max(nums[i],max(minend,maxend));
            res=max(res,maxvalue);
        }
        return res;
    }
};
```