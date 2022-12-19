![6cf4cc768e1ff6da13930497d9e5a8c.png](https://pic.leetcode-cn.com/c46b80417dd85096f11704a1d13b1088c92e5349b4b816e82be3ce87790efaa8-6cf4cc768e1ff6da13930497d9e5a8c.png)
```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()||s.size() == 1) return s;
        string a = chg(s);
        int len = a.size();
        vector<int> p(len,0);
        int c = 0;
        int r = 1;
        int mxc = c;
        int mxr = r;
        int next = 1;
        p[0] = 1;
        while(next !=len)
        {
            if(next > c+r-1)
            {
                int m = 1;
                if(next-m>-1&&next+m<len)
                {
                    while(a[next+m] == a[next-m]) 
                    {
                        m++;
                        if(next-m<=-1||next+m>=len)break;
                    }
                }
                p[next] = m;
                c = next;
                r = m;
                next++;
                if(r > mxr)
                {
                    mxr = r; mxc = c;
                }
                continue;
            }
            else if(2*c-next-p[2*c-next] > c-p[c])
            {
                p[next] = p[2*c-next];
                next++;
                continue;
            }
            else if(2*c-next-p[2*c-next] < c-p[c])
            {
                p[next] = c+r-next;
                c = next;
                r = p[next++];
                continue;
            }
            else if(2*c-next-p[2*c-next] == c-p[c])
            {
                int m = p[2*c-next];
                if(next-m>-1&&next+m<len)
                {
                    while(a[next+m] == a[next-m]) 
                    {
                        m++;
                        if(next-m<=-1||next+m>=len)break;
                    }
                }
                p[next] = m;
                c = next;
                r = m;
                if(r > mxr)
                {
                    mxr = r; mxc = c;
                }
                next++;
            }
        }
        return s.substr((mxc - mxr + 1) / 2, mxr - 1);
    }
    
    string chg(string s)
    {
        string ans;
        for(int m = 0; m <s.size(); m++)
        {
            ans += '#';
            ans += s[m];
        }
        ans += '#';
        return ans;
    }
};

```
