```
class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int len=s.length();
        int start=0;
        int end;
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ')
            {
                end=i;
                for(int j=end-1;j>=start;j--)
                {
                    res+=s[j];
                }
                res+=" ";
                start=end+1;
            }
            if(i==len-1)
                for(int j=i;j>=start;j--)
                    res+=s[j];
        }
        return res;
    }
};
```
