```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_map<int,int> m;
         for(int i=0;i<nums.size();i++){
             if(m.find(nums[i])!=m.end())//如果前面已经存在这个数
                  return true;
             m[nums[i]]=i;
         }
         return false;
    }
};
```
