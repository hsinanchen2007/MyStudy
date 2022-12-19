```
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        map<int,int> count;
        for(auto num : nums)
        {
            count[num] += 1;
            if(count[num] == 2) res.push_back(num);
        }
        for(int num=1;num<=nums.size();num++)
        {
            if(count.find(num) == count.end())
            {
                res.push_back(num);
                break;
            }
        }
        return res;
    }
};
```