### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0) return -1;
        int tmp = nums[0]; 
        int num = 1;
        for(int i = 1; i < n; i++)
        {
            if(tmp == nums[i]) num++;
            else
            {
                num--;
                if(num == 0)
                {
                    tmp = nums[i+1];
                }
            } 
        }
        num = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == tmp) num++;
            else num--;
        }
        return num ? tmp : -1;
    }
};
```