class Solution {
public:
    string intToRoman(int num) {
        string res;
        while(num>=1000)
        {
            res+='M';
            num-=1000;
        }     
        while(num>=900)
        {
            res+="CM";
            num-=900;
        }
        while(num>=500)
        {
            res+='D';
            num-=500;
        }
        while(num>=400)
        {
            res+="CD";
            num-=400;
        }
        while(num>=100)
        {
            res+='C';
            num-=100;
        }
        while(num>=90)
        {
            res+="XC";
            num-=90;
        }
        while(num>=50)
        {
            res+='L';
            num-=50;
        }
        while(num>=40)
        {
            res+="XL";
            num-=40;
        }
        while(num>=10)
        {
            res+='X';
            num-=10;
        }
        if(num==9)
        {
            res+="IX";
            return res;
        }
        else
        {
            if(num>=5)
            {
                res+='V';
                num-=5;
            }
            else if(num==4)
            {
                res+="IV";
                return res;
            }
            while(num!=0)
            {
                res+='I';
                num--;
            }
        }
        return res;   
    }
};