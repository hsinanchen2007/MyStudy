```
class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        int i=0;
        while(i<s.size()){
            switch(s[i]){
                case 'M':res+=1000;break;
                case 'C':
                    if(i+1<s.size()&&s[i+1]=='M')res+=900,++i;
                    else if(i+1<s.size()&&s[i+1]=='D')res+=400,++i;
                    else res+=100;
                    break;
                case 'D':res+=500;break;
                case 'L':res+=50;break;
                case 'X':
                    if(i+1<s.size()&&s[i+1]=='C')res+=90,++i;
                    else if(i+1<s.size()&&s[i+1]=='L')res+=40,++i;
                    else res+=10;
                    break;
                case 'V':res+=5;break;
                case 'I':
                    if(i+1<s.size()&&s[i+1]=='X')res+=9,++i;
                    else if(i+1<s.size()&&s[i+1]=='V')res+=4,++i;
                    else res+=1;
                    break;
            }
            ++i;
        }
        return res;
    }
};
```
