```
class Solution {
public:
    string reverseWords(string s) {
        
        if(!s.size()) return "";
        int start=0,end=s.size()-1;

        reverse(s.begin(),s.end());
        while(start<s.size()&&s[start]==' ') start++;
        while(end>=0&&s[end]==' ') end--;
        if(start>end) return "";

        for(int r=start;r<=end;)
        {
            while(r<=end&&s[r]==' ') r++;
            int l=r;
            while(l<=end&&s[l]!=' ') l++;
            reverse(s.begin()+r,s.begin()+l);
            r=l;
        }

        int tail=start;
        for(int i=start;i<=end;i++)
        {
            if(s[i]==' '&&s[i-1]==' ') continue;
            s[tail++]=s[i];
        }
        return s.substr(start,tail-start);
    }

};
```
