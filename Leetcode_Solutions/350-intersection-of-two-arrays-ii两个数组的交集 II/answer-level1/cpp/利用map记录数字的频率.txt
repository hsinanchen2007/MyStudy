```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> ret;
        for(auto n:nums1)
        {
            map<int,int>::iterator it = mp.find(n);
            if(it == mp.end())
            {
                mp.insert(pair<int,int>(n,1));
            }
            else
            {
                it->second++;
            }
        }
        for(auto n:nums2)
        {
            map<int,int>::iterator it = mp.find(n);
            if(it != mp.end() && it->second-- > 0)
            {
                ret.push_back(n);
            }
        }
        return ret;
    }
};
```
