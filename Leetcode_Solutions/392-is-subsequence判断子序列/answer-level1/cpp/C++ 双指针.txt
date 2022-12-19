
简单题，没啥说的，直接上代码了：
```
bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        if(n==0 && m==0)
            return true;
        if(n==0 && m!=0)
            return false;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(t[j]!=s[i])
            {
                j++;continue;
            }
            if(t[j]==s[i])
            {
                j++;i++;
            }
        }
        return i<m?false:true;
    }
```
