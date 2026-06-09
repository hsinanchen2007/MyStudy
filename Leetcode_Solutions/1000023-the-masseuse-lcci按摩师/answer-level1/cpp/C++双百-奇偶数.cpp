
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) 
    {
        int even = 0;
        int odd = 0;
        int total = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i % 2 == 0)
            {
                even += nums[i];
                total = max(even, odd);
                even = total;
            }
            else
            {
                odd += nums[i];
                total = max(even, odd);
                odd = total;
            }
        }
        return total;
    }
};
```