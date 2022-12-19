```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>a;
        int cnt=0;
        for(int i=0,j=0;j<s.length();j++)
        {
            if(a.find(s[j])!=a.end())
            {
                i = a[s[j]]+1;
                j = a[s[j]]+1;
                a.clear();
                a[s[i]] = i;
            }
            else
                a[s[j]]=j;
            if(cnt<j-i+1)
                cnt = j-i+1;
        }
        return cnt;
    }
};
```
