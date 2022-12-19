### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> a(n+1, 0);//输入的数值是少一个的 有可能越界 所以要+1
        for(int i = 0; i < n; i++)
        {
            a[nums[i]] = -1;
        }
        for(int i = 0; i <= n; i++)
        {
            if(a[i] == 0) return i;
        }    
        return -1;  
    }
};
```