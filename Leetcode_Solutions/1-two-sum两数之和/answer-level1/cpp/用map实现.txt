class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> record;
        int compile=0;
        int index=0;
        vector<int> two;
        for(auto a:nums)
        {
            compile=target-a;
            if(record.find(compile)!=record.end())
            {
                  two.push_back(record.find(compile)->second);
                  two.push_back(index);
                  break;
            }
            else
                record.insert({a,index});
            index++;
        }
        return two;
    }
};