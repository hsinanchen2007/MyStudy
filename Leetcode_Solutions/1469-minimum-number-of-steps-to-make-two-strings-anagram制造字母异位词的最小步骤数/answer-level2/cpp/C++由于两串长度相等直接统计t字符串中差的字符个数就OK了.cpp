```
class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mps,mpt;
        vector<char>a;
        for(int i=0;i<s.size();i++){
            if(mps.find(s[i])==mps.end())a.push_back(s[i]);
            mps[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
           // if(mpt.find(t[i])==mpt.end())a.push_back(s[i]);
            mpt[t[i]]++;
        }
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(mpt.find(a[i])==mpt.end()){ans+=mps[a[i]];
        continue;
        }
                ans+=(mps[a[i]]-mpt[a[i]]>=0?mps[a[i]]-mpt[a[i]]:0);
        }
        return ans;
    }
};
```
