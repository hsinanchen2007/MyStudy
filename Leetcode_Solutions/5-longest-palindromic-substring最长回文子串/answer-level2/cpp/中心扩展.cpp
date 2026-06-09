```
class Solution {
    int res;
    int hh,tt;
public:
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            serach(s,i,i);
            if(i!=s.size()-1) serach(s,i,i+1);
        }
        return  s.substr(hh,res);
    }
    void serach(string &s,int l,int r)
    {
        if(s[l]!=s[r]) return;
        int cnt = l == r ? 1 : 2;
        l--,r++;
        while(l >= 0 && r < s.size())
        {
            if(s[l]==s[r])  cnt+=2;
            else{
                if(res < cnt)
                {
                    res = cnt;
                    hh = l + 1;
                    tt = r - 1;
                }
                break;
            }
            l--,r++;
        }
        if(res < cnt)
        {
            res = cnt;
            hh = l + 1;
            tt = r - 1;
        }
    }
};
```
