### 解题思路

### 代码

```cpp
class Solution 
{
public:
    string longestPalindrome(string& s) 
    {
        return Manacher(s);
    }

    string Manacher(string& s)
    {
        if(s.size()<=1) return s;

        string t="@#";
        for(int i=0;i<s.size();i++) 
            t+=s[i],t+="#";

        int mcen=0,mpos=0,mr=0;
        vector<int> r(t.size(),0);

        for(int cen=1;cen<t.size()-1;cen++)
        {
            if(cen<mpos) 
                r[cen]=min(r[2*mcen-cen],mpos-cen);
            else r[cen]=1;

            while(t[cen-r[cen]]==t[cen+r[cen]]) 
                r[cen]++;

            if(r[cen]>mr)
                mr=r[cen],mcen=cen,mpos=cen+r[cen];
        }

        return string(s,(mcen-mr)/2,mr-1);
    }
};
```