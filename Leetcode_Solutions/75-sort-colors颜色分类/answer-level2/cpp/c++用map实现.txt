class Solution {
public:
    void sortColors(vector<int>& nums) {
        //用map的思想
        map<int,int> maps;
        for(auto x:nums){
            maps[x]++;
        }
        nums.clear();
        for(auto it=maps.begin();it!=maps.end();it++){
            for(int i=0;i<it->second;i++){
                nums.push_back(it->first);
            }
            //cout<<it->first<<" "<<it->second;
        }

    }
};