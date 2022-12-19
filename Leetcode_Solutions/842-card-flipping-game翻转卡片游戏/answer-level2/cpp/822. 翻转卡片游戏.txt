法一：有点慢

```
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> s;
        set<int> s1;
        int n=fronts.size();
        for(int i=0;i<n;++i)
        {
            if(fronts[i]==backs[i])
                s.insert(fronts[i]);
            else
            {
                s1.insert(fronts[i]);
                s1.insert(backs[i]);
            }
        }

        for(auto it=s1.begin();it!=s1.end();++it)
        {

            if(s.find(*it)==s.end())
            {
                return *it;
            }

        }
        return 0;
    }
};
```

法二：
```
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> s;
        int n=fronts.size();
        for(int i=0;i<n;++i)
        {
            if(fronts[i]==backs[i])
                s.insert(fronts[i]);
        }

        int res=INT_MAX;
        for(int i=0;i<n;++i)
        {
            if(fronts[i]==backs[i])
                continue;
            if(backs[i]<res)
            {
                if(s.find(backs[i])==s.end())
                {
                    res=min(res,backs[i]);
                }
            }
            if(fronts[i]<res)
            {
                if(s.find(fronts[i])==s.end())
                {
                    res=min(res,fronts[i]);
                }
            }
        }
        return res==INT_MAX?0:res;
    }
};
```

