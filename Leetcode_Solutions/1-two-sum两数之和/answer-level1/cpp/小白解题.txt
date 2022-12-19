### 解题思路
用的暴力求解法，时间复杂度太高，没想起哈希表

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {    
        int i;
        vector<int> two_Sum(2);
        for(i=0 ; i<nums.size();i++)
        {
                int j = target - nums[i];
                for(int k=i+1 ; k<nums.size();k++)
                {
                    if(nums[k] == j )
                    {
                        two_Sum[0] = i;
                        two_Sum[1] = k;                      
                        break;   
                    }
                }
        }
        return two_Sum;
    }
};
```