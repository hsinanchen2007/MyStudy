```
class Solution {
public:
    int res,size1,size2;
    int cnt[100005];
    bool judge;
    map<int,unordered_set<int>> mp;//map的first为数出现的次数，second为出现这个次数的数的集合
    int maxEqualFreq(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            judge = false;
            if(cnt[nums[i]]) {
                mp[cnt[nums[i]]].erase(nums[i]);
                if(!mp[cnt[nums[i]]].size()) mp.erase(cnt[nums[i]]);   
            }
            mp[++cnt[nums[i]]].insert(nums[i]);
            size1 = ((mp.rbegin())->second).size();
            size2 = ((mp.begin())->second).size();
            //三种可能的情况考虑，找到最大值
            if(mp.size()==1&&(size2==1||mp.begin()->first==1)) judge = true;
            else if(mp.size()==2) {
                if(mp.begin()->first+1==mp.rbegin()->first&&mp.rbegin()->second.size()==1) judge = true;
                if(mp.begin()->first==1&&mp.begin()->second.size()==1) judge = true;
            }
            if(judge) res = max(res,i+1);
        }
        return res;
    }
};
```
