### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());//递减排列
        vector<int> res;
        int sum1 = 0;
        int sum2 = 0;
        int k = 0;
        for(int i = 0;i < nums.size();i++)
        {
            sum1 = sum1 + nums[i];    
        }
        while(sum2 <= sum1)
        {
            res.push_back(nums[k]);
            sum2 += nums[k];
            sum1 -= nums[k];
            k++;
        }
        return res;
    }
};

```