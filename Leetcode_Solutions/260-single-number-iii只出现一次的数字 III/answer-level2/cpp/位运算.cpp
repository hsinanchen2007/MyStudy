挺简单的
```c++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0,t=0;
        for(auto c:nums)res^=c;
        int diff = res&(-res);
        for(auto c:nums){
            if(c & diff)t^=c;
        }
        return {t,res^t};
    }
};
```