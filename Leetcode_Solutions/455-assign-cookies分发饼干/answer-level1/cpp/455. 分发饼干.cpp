```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng=g.size();
        int ns=s.size();
        if(ng&&ns)
        {
            stable_sort(g.begin(),g.end());
            stable_sort(s.begin(),s.end());
            int idg=0;
            int ids=0;
            int res=0;
            while((idg<ng) && (ids<ns))
            {
                if(s[ids]>=g[idg])
                {
                    ++res;
                    ++ids;
                    ++idg;
                }
                else
                {
                    ++ids;
                }
            }
            return res;
        }
        else
        {
            return 0;
        }
    }
};
```

```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng=g.size();
        int ns=s.size();
        if(ng&&ns)
        {
            stable_sort(g.begin(),g.end());
            stable_sort(s.begin(),s.end());
            vector<int>::iterator idg=g.begin();
            vector<int>::iterator ids=s.begin();
            int res=0;
            while(idg!=g.end() && ids!=s.end())
            {
                if(*ids >= *idg)
                {
                    ++res;
                    ++ids;
                    ++idg;
                }
                else
                {
                    ++ids;
                }
            }
            return res;
        }
        else
        {
            return 0;
        }
    }
};
```

