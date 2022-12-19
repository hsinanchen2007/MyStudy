### 解题思路
给定一个数，在数组中寻找三个数，使得它们之和最接近目标数。
主要分两种情况：
第一种：相等，直接跳出循环
第二种：不相等，设置初始最接近目标数值close，遍历，每次越接近目标数，就把该数组中的数值组合赋给close
采用两个循环，遍历内循环采用双指针索引数组，更快。

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        bool flag = 0;
        int close = nums[0] + nums[1] + nums[2];
        int close2 = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();i++)
        {
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {  

                if(nums[i] + nums[j] + nums[k] == target)
                {
                    close = target;
                    flag = 1;
                    break;
                }
                else if(nums[i] + nums[j] + nums[k] > target)
                {
                    result = nums[i] + nums[j] + nums[k];                    
                    if(abs(target - close2) > abs(target - result))
                        close2 = result;
                    k--;
                    continue;
                }
                else{
                    result = nums[i] + nums[j] + nums[k];                    
                    if(abs(target - close2) > abs(target - result))
                        close2 = result;                    
                    j++;
                    continue;
                }
            }

            if(flag == 1)
            break;
            if(abs(close - target) > abs(close2 - target))
                close = close2;

        }
        return close;
        
    }
};
```