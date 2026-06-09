### 解题思路
要求算法On,维护三个数就好了，嘻嘻，注意初始化为LONG_MIN,坑了很久，
最后的时候确定一下third是否仍为LONG_MIN就好了

### 代码

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
            int len=nums.size();
            if(len==1)
                return nums[0];
            if(len==2)
                return nums[0]>nums[1]?nums[0]:nums[1];
            long int first = LONG_MIN;
            long int second = LONG_MIN;
            long int third =LONG_MIN;
            for(int i = 0 ;i < len; i++)
            {
                if(nums[i] > first)
                {
                    third = second;
                    second = first;
                    first = nums[i];
                }
                else if(nums[i] > second && nums[i] != first)
                {
                    third = second;
                    second = nums[i];
                }
                else if (nums[i] >= third && nums[i] != second && nums[i]!=first)
                {
                    third = nums[i];
                }
            }
            return third==LONG_MIN ? first:third;
    }
};
```