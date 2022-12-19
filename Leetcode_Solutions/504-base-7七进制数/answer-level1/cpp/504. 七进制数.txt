```
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)return "0";
        bool neg=false;
        if(num<0)
        {
            neg=true;
            num=-num;
        }

        string s="";
        while(num>0)
        {
            s.insert(0,1,(char)(num%7+48));
            num/=7;
        }
        if(neg)
        {
            s.insert(0,1,'-');
        }
        return s;
    }
};
```
