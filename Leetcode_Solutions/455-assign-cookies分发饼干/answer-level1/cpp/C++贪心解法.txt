先排序两个数组，然后再利用双指针，简单易懂
```
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int glen=g.size(),slen=s.size(),ans=0;
        int i=0,j=0;
        while(i<glen && j<slen)
        {
            if(g[i]>s[j])
            {
                j++;
            }
            else
            {
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
```
