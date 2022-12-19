```
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        int i,j;
        for(auto x:d){
            for(i=0,j=0;i<x.size()&&j<s.size();i++){
                while(j<s.size()&&s[j]!=x[i])j++;j++;
            }
            if(i==x.size()&&j<=s.size())
                if(i>ans.size()||(i==ans.size()&&ans>x))ans=x;
        }
        return ans;
    }
};
```


```
class Solution {
public:
    static bool fun(const string &a, const string &b)
    {
	    if (a.size() == b.size())return a < b;
	    else return a.size() > b.size();
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),fun);
        int i,j;
        for(auto x:d){
            for(i=0,j=0;i<x.size()&&j<s.size();i++){
                while(j<s.size()&&s[j]!=x[i])j++;j++;
            }
            if(i==x.size()&&j<=s.size())
                return x;
        }
        return "";
    }
};
```

