### 解题思路
先建立一个容器存储从前到后的和，然后来判断。
注意除数不能为零！！！

### 代码

```cpp
class Solution {
    vector<int> p;
    void dp(vector<int>& nums)
    {
        int sum = 0;
        p.push_back(sum);
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            p.push_back(sum);
        }
    }
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        if(nums.size() < 2) return false;
        
        dp(nums);
        for(int i = 2;i<=nums.size();i++)
        {
            if(k == 0)
            {
                for(int j = 0;j<=i-2;j++)
                {
                    if(p[i]-p[j]==0)
                    return true;
                }
            }
            else
            for(int j = 0;j<=i-2;j++)
            if((p[i]-p[j])%k == 0)
                return true;
        }
        return false;
    }
};
```