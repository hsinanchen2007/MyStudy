```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; i++) {
            int sum = 0;
            for(int num:nums) {
                num >>= i;
                sum += (num & 1);
            }
            res |= ((sum % 3) << i);
        }
        return res;
    }
};
```
