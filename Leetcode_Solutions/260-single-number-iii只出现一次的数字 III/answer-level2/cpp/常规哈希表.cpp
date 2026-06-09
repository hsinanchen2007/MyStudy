```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> numbers;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            numbers[nums[i]]++;
        }
       for(unordered_map<int,int>::iterator it=numbers.begin();it!=numbers.end();it++)
       {
           if(it->second==1)
               res.push_back(it->first);
       }
        return res;
    }
};
```
