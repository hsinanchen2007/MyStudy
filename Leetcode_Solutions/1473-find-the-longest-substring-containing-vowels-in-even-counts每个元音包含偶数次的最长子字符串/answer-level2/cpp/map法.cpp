map用的不太熟练，写的有些冗余

```
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int,int> mp;int cur=0,h=0,ans=0;
        pair<map<int,int>::iterator,bool> ret;
        map<int,int>::iterator it;
        mp.insert(make_pair(0,0));
        for(auto v:s){
            cur++;
            if(v=='a')h^=1;
            else if(v=='e')h^=2;
            else if(v=='i')h^=4;
            else if(v=='u')h^=8;
            else if(v=='o')h^=16;
            ret=mp.insert(make_pair(h,cur));
            if(!ret.second)
            {it=mp.find(h);ans=max(ans,cur-it->second);}
        }
return ans;
    }
};
```
