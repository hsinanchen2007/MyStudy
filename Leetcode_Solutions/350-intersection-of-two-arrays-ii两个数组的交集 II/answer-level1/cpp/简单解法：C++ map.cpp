```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> dict;
        for(auto key : nums1)
        {
            dict[key] += 1;
        }

        for(auto key : nums2)
        {
            if(dict[key] > 0)
            {
                res.push_back(key);
                dict[key] -= 1;
            }
        }

        return res;
    }
};
```