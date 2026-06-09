
下面这个:680ms
```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int num=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        while(g.begin()!=g.end()&&s.begin()!=s.end()){
            if(s[0]>=g[0]){
                ++num;
                s.erase(s.begin());
                g.erase(g.begin());
            }
            else
                s.erase(s.begin());       
        }
    return num;
    }
};
```

如果不用erase这种函数,改成下面这个,44ms
```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int num=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        while(i<s.size()&&j<g.size()){
            if(s[i]>=g[j]){
                ++num;
                ++i;
                ++j;
            }
            else
                ++i;       
        }
    return num;
    }
};
```
简单就是美

