### 解题思路
在每一个i的范围内寻找可以往后走的更多的那个，比如第一个位置是7，那就在第0到第6个位置上找，如果第3个位置上是8，那就说明可以走8+3=11，但是第6个位置上是9，那么他可以往后走6+5=15，所以选往后走的最多的那个，**每次都选走的最多的那个**，直到往后走的大于nums.size()-1，体现贪婪是思想

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size()==1) return 0;//判断[0]
        int count = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]+i >= nums.size()-1) return count;//如果能达到最后一位就返回
            int max_step = 0;
            int tmp = 0;
            for (int j = 1; j <= nums[i]; j++)//贪婪的核心
            {
                if(j + nums[i+j] >= max_step)
                {
                    max_step = j + nums[i+j];
                    tmp = j;
                }
            }
            i += tmp-1;
            count++;            
        }
        return 0;  
        
    }
};
```