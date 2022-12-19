代码在这，自己看

```
class Solution {
public:
    
    int rob(vector<int>& nums) 
    {
       int len = nums.size();
        if(len==1) return nums[0];
        int record[170] = {0};
        int record2[170] ={0};
        
        
        for(int i=2;i<=len;i++)
        {
            record[i] = max(record[i-1],record[i-2]+nums[i-2]);
            record2[i] = max(record2[i-1],record2[i-2]+nums[i-1]);
        }
        
        return std::max(record[len],record2[len]);
        
    }
        
        
    
};
```
