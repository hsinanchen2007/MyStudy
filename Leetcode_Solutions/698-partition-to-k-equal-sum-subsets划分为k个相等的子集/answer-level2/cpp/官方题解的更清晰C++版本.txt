### 解题思路
官方题解的更清晰C++版本
执行用时 :16 ms, 在所有 C++ 提交中击败了52.60%的用户
内存消耗 :19.4 MB, 在所有 C++ 提交中击败了6.06%的用户
### 代码

```cpp
class Solution 
{
public:
    bool search(int used,int sum,vector<int>& f,vector<int>& nums,int target)
    {
        if(f[used] == -1)
        {
            f[used] = 0;

            //为了限定本组，防止选择的物品跨组，下面是保证当sum为target时，取余仍为target
            int localtarget = (sum - 1) % target + 1;

            for(int i = 0;i < nums.size();i++)
            {
                if((((used >> i) & 0x01) == 0) && (nums[i] <= localtarget))
                {
                    if(search(used | (1 << i),sum - nums[i],f,nums,target))
                    {
                        f[used] = 1;
                        break;
                    }
                }
            }
        }

        return f[used] == 1;
    }

    bool canPartitionKSubsets(vector<int>& nums,int k) 
    {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % k != 0)
        {
            return false;
        }
        
        vector<int> f(1 << nums.size(),-1);
        f[(1 << nums.size()) - 1] = 1;
        return search(0,sum,f,nums,sum / k);
    }
};
```