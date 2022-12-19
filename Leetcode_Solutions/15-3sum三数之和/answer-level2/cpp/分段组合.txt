```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> st;
        vector<int> left;
        vector<int> right;
        vector<vector<int>> ret;
        int l = 0;
        int r = nums.size()-1;
        for(auto n:nums)
        {
            if(st.count(n)<=0)
            {
                if(n<0)
                    left.push_back(n);
                else if(n>0)
                    right.push_back(n);
            }
            st[n]++;
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int count = 0;
        int m = 0;
        int n = 0;
        for(auto l:left)
        {
            if(right.empty())
                break;
            if(l + right[right.size()-1]*2 < 0)
                continue;
            for(auto r:right)
            {
                if(right[right.size()-1]+l+r<00)
                {
                    continue;
                }
                if(left[0]+l+r>0)
                    break;
                m = 0-l-r;
                count = st[m];
                n = 0;
                if(m==l || m==r)
                    n++;
                if(count > n)
                {
                    if(m<=l || m>=r || m == 0)
                        ret.push_back({l, r, m});
                }
            }
        }
        if(st[0] >= 3)
        {
            ret.push_back({0,0,0});
        }
        return ret;
    }
};
```
