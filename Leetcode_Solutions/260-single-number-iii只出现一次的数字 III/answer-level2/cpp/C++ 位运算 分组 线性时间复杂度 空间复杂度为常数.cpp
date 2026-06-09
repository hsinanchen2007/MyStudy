```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret(2,0);
        int tp = 0;
        for(int i=0;i<nums.size();i++){
            tp = tp ^ nums[i];
        }
        int base = 1;
        while(true){
            if(base & tp){
                break;
            }else{
                base <<= 1;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(base & nums[i]){
                ret[0] = ret[0] ^ nums[i];
            }else{
                ret[1] = ret[1] ^ nums[i];
            }
        }
        return ret;
    }
};
```
