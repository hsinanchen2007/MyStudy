
思路：将数组假装变成两个一模一样的数组，然后统计hash[nums[i]] 的值。
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int,int>hash;
        
        int val=0;
        int len=nums.size();
        for(int i=0;i<len*2;i++)  
        {
 
            if(i>=len&&hash[nums[i%len]]==1)
            {    
                val=nums[i%len];
                break;
            }
            hash[nums[i%len]]++;
        }
        return val;
    }
};

```
