暴力方法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int j=0;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            nums[j]=it->first;
            j++;
            
        }
        return mp.size();
    }
};