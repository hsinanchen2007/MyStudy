```
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int number = 0;
        vector<int> res(2,0);
        for(int num:nums) number ^= num;
        int pos = number&(-number);  // 找到最低位起1出现的位置
        for(int num:nums){
            if((num & pos) == pos) res[0] ^= num;
            else res[1]^=num;
        }
        return res;
    }
};
```
