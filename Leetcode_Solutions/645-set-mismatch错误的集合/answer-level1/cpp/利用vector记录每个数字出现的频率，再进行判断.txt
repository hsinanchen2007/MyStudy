```
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret(2, 0);
        vector<int> ct(nums.size()+1, 0);
        for(auto n:nums)
        {
            if(ct[n] == 1)
            {
                ret[0] = n;
            }
            ct[n]++;
        }
        for(int i=1; i<=nums.size(); i++)
        {
            if(ct[i] == 0)
            {
                ret[1] = i;
                break;
            }
        }
        return ret;
    }
};
```
