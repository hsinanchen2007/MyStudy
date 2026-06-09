### 解题思路
遍历一次数组，当前和 presum，最大和 maxsum；
1. presum > 0 时当前的和才有意义，即 presum + nums[i] > nums[i] 时才有意义；
2. presum <= 0 时候应当舍弃前面的累加，presum 重置为当前元素 num[i]；

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, len = nums.size();
        if( len <= 0 ) return 0;

        int presum = 0, maxsum = nums[0];
        for( i=0; i<len; i++ )
        {
            if( presum > 0 )
                presum += nums[i];
            else
                presum = nums[i];
                
            if( presum > maxsum )
                maxsum = presum;
        }
        return maxsum;
    }
};
```