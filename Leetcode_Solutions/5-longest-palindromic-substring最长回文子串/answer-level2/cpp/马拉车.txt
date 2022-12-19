```c++
class Solution {
public:
    string longestPalindrome(string s) {
        string news="$#";
        for(char c:s){news+=c;news+='#';}
        int len = news.length();
        int *p = new int[len+1];
        int mxlen=-1,mxpos=0;
        int id,mx=0;
        for(int i=1;i<=len;i++){
            p[i]=(i<mx)?(min(mx-i,p[2*id-i])):(1);
            while(news[i-p[i]]==news[i+p[i]]) p[i]++;
            if(mx<i+p[i]){
                id=i;
                mx=i+p[i];
            }
            if(p[i]-1>mxlen){mxlen=p[i]-1;mxpos=i;}
        }
        string ret="";
        for(int i=mxpos-mxlen;i<=mxpos+mxlen;i++) if(news[i]!='#') ret+=news[i];
        return ret;
    }
};
```
时间: 6ms 98% 
空间: 100%
每次拿id和mx去更新i

