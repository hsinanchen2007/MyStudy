```
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if(nums.size()%2==0)return true;
        int tmp=0;
        for(int n:nums)tmp^=n;
        return (tmp==0);
    }
};
```
