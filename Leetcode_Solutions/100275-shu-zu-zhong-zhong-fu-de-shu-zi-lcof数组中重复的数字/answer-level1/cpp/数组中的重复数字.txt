class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int j=0;
        for(j=0;j<mp.size();j++){
            if(mp[nums[j]]>1){
                break;
            }
        }
        return nums[j];
    }
};