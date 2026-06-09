
string类成员函数inset
```
class Solution {
public:
    string convertToBase7(int num)
    {
        if(num==0)
        return "0";
        string c="";
        bool flag=false;
        if(num<0)
        {
            flag=true;
            num=-1*num;
        }
        while(num>0)
        {
            c.insert(0,1,(char)(num%7+48));
            num/=7;
        }
        if(flag)
        c.insert(0,1,'-');
        return c;
    }
};

```