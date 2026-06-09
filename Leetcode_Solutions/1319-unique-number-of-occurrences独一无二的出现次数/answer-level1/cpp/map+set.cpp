1.map统计各个数字出现次数
2.set记录出现次数
```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto& i : arr)mp[i]++;
        set<int> st;
        for(auto& m:mp){
            if(st.find(m.second)!=st.end())return false;
            st.insert(m.second);
        }
        return true;
    }
};
```
