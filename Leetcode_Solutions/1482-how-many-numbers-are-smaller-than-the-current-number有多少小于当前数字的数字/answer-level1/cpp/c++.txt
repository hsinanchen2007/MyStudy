```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<nums.size();j++){
                if(temp[i]==nums[j]){
                     res.push_back(j);
                    break;
                }                
            }
        }
        return res;
    }
};
```
