```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int max_count = 0;
        
        for(auto i:nums){
            
            if(i==1){
                count++;
                max_count = max(max_count, count);

            }
            else
                count=0;
        }
        
        return max_count;
        
    }
};
```
