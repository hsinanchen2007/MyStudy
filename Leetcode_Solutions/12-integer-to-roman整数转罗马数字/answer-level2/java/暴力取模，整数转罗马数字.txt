一点一点取模总会求出来的😀😀
``` 
public String intToRoman(int num) {
        StringBuilder res =new StringBuilder();
        if(num/1000 ==1)
            res.append("M");
        else if(num/1000 ==2)
            res.append("MM");
        else if(num/1000 ==3)
            res.append("MMM");

        num=num%1000;

        if(num/100==1)
            res.append("C");
        else if(num/100==2)
            res.append("CC");
        else if(num/100==3)
            res.append("CCC");
        else if(num/100==4)
            res.append("CD");
        else if(num/100==5)
            res.append("D");
        else if(num/100==6)
            res.append("DC");
        else if(num/100==7)
            res.append("DCC");
        else if(num/100==8)
            res.append("DCCC");
        else if(num/100==9)
            res.append("CM");

        num=num%100;
        if(num/10==1)
            res.append("X");
        else if(num/10==2)
            res.append("XX");
        else if(num/10==3)
            res.append("XXX");
        else if(num/10==4)
            res.append("XL");
        else if(num/10==5)
            res.append("L");
        else if(num/10==6)
            res.append("LX");
        else if(num/10==7)
            res.append("LXX");
        else if(num/10==8)
            res.append("LXXX");
        else if(num/10==9)
            res.append("XC");
        
        num=num%10;
        
        if(num==1)
            res.append("I");
        else if(num==2)
            res.append("II");
        else if(num==3)
            res.append("III");
        else if(num==4)
            res.append("IV");
        else if(num==5)
            res.append("V");
        else if(num==6)
            res.append("VI");
        else if(num==7)
            res.append("VII");
        else if(num==8)
            res.append("VIII");
        else if(num==9)
            res.append("IX");
        return res.toString();
    }




