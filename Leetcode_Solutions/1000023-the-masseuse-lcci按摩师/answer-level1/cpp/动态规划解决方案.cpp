### 解题思路
利用动态规划来解决此题。
1、题意可得取得数字不能相邻，那么最后结果可能的情况就是nums[i] + nums[i - 2] 或者 nums[i - 1]，（就是算上自己或者不算上自己，算上自己的话，就可以加上nums[i - 2]，不算自己的话，就是nums[i - 1]）
 2、具体代码如下

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) 
    {
            int total_size = nums.size();
            if(0 == total_size)
            {
                return 0;
            }

            for(int i = 0; i < total_size; ++i)
            {
                if(i >= 2)
                {
                    int tmp = nums[i - 2] + nums[i];
                    if(tmp > nums[i - 1])
                    {
                        nums[i] = tmp;
                    }
                    else
                    {
                        nums[i] = nums[i - 1];
                    }
                }
                 else if(i == 1)
                 {
                    nums[i] = nums[i] > nums[i - 1] ? nums[i] : nums[i - 1];
                 }
            }

            return nums[total_size - 1];
    }
};
```