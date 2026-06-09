class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i =0;i<nums.size();i++){
            int k = target - nums[i];
            if(m.find(k)!=m.end()){
                vector<int> v;
                v.push_back(i);
                v.push_back(m[k]);
                return  v;
            }
              m[nums[i]]=i;
        }
        vector<int> v;
        return v;

    }
};