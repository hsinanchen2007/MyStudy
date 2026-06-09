```
class Solution {
public:
    string intToRoman(int num) {
        int m=0,d=0,c=0,l=0,x=0,v=0,i=0;
        m=num/1000;
        num%=1000;
        int cm=num/900;
        num%=900;
        d=num/500;
        num%=500;
        int cd=num/400;
        num%=400;
        c=num/100;
        num%=100;
        int xc=num/90;
        num%=90;
        l=num/50;
        num%=50;
        int xl=num/40;
        num%=40;
        x=num/10;
        num%=10;
        int ix=num/9;
        num%=9;
        v=num/5;
        num%=5;
        int iv=num/4;
        num%=4;
        i=num;
        string res;
        while(m-->0)res+='M';
        while(cm-->0)res+="CM";
        while(d-->0)res+='D';
        while(cd-->0)res+="CD";
        while(c-->0)res+="C";
        while(xc-->0)res+="XC";
        while(l-->0)res+="L";
        while(xl-->0)res+="XL";
        while(x-->0)res+="X";
        while(ix-->0)res+="IX";
        while(v-->0)res+="V";
        while(iv-->0)res+="IV";
        while(i-->0)res+="I";
        return res;
    }
};
```
