```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;++i)
        {
            ++m[arr[i]];
        }

        unordered_set<int>s;
        for(auto it=m.begin();it!=m.end();++it)
        {
            if(s.find(it->second)==s.end())
            {
                s.insert(it->second);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
```
