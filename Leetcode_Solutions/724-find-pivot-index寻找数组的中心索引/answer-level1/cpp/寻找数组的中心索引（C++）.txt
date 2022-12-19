### 解题思路
1. 核心
- 先求数组所有元素总和sum，再从索引0开始求left_sum，
- 并判断left_sum是否是除中心索引外剩余元素和的一半

2. 注意
- 1.如果输入为空[]，那么left_sum = nums[0]将会溢出，因此赋值left_sum初始值应为0；
- 2.对于[0,0,0]，应返回0，因为0的左侧没有元素相当于0，右侧全是0，相等
- 3.同时，也存在中心索引在最右的情况[-1,-1,0,1,1,0]，输出为5

3. 复杂度分析
- 时间复杂度：O(n)
- 空间复杂度：O(1)

### 代码

```cpp


// 注意：


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, len = nums.size(), sum = 0, left_sum = 0;
        for(i=0; i<len; i++)
            sum += nums[i];
        // left_sum != (sum - nums[i])/2  不能用/2判断，可能会有数据舍弃，导致结果错误
        for(i=0; i<len; i++)
        {
            if(left_sum*2 + nums[i] == sum)
                return i;
            left_sum += nums[i];
        }
        return -1;
    }
};
```