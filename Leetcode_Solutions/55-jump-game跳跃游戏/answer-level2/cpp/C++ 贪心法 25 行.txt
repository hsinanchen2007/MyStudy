```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        
        while(pos<nums.size()-1){
            if(nums[pos] == 0)
                return false;
            
            int next_pos = pos + 1;
            int next_max_pos = next_pos + nums[next_pos];
            for(int i=pos+1;i<nums.size() && i<=nums[pos]+pos;i++){
                if((nums[i]+i) > next_max_pos){
                    next_pos = i;
                    next_max_pos = nums[i] + i;
                }
            }
            pos = next_pos;
        }
        
        return true;
    }
};
```
