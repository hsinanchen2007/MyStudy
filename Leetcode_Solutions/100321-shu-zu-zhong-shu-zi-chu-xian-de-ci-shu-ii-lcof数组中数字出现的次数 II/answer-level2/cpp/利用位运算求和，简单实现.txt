```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int bitSum[32] = {0};
        
        for(int i = 0; i < length; i++){
            unsigned int bitMask = 1;
            for(int j = 31; j >= 0; j--){
                if((nums[i] & bitMask) != 0)
                    bitSum[j]++;
                bitMask <<= 1;
            }
        }
        
        int res = 0;
        for(int i = 0; i < 32; i++){
            res <<= 1;
            res += bitSum[i] % 3;
        }
        
        return res;
    }
};
```
