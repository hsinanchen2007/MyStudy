用DPS来将输入的数字进行依次减少，取得最合适的罗马数字并依次累加到字符串中。

```
class Solution {
public:
    void transit(int &num,string& str)
    {
        if(num == 0)
        return;    
        if(num>0&&num<=3)
        {
            num = num - 1;
            str = str +"I";
            transit(num,str);
        }
        if(num==4)
        {
            num = num - 4;
            str = str +"IV";
            transit(num,str);
        }
          if(num>=5&&num<9)
        {
              num = num - 5;
            str = str +"V";
            transit(num,str);
        }
        if(num==9) 
        {
            num = num - 9;
            str = str +"IX";
            transit(num,str);
        }
        if(num>=10&&num<=39) 
        {
            num = num - 10;
            str = str +"X";
            transit(num,str);
        }

            if(num>=40&&num<=49) 
        {
            num = num - 40;
            str = str +"XL";
            transit(num,str);
        }
        
         if(num>=50&&num<=89) 
        {
            num = num - 50;
            str = str +"L";
            transit(num,str);
        }
        
      if(num>=90&&num<=99) 
        {
            num = num - 90;
            str = str +"XC";
            transit(num,str);
        }
      if(num>=100&&num<=399) 
        {
            num = num - 100;
            str = str +"C";
            transit(num,str);
        }
      if(num>=400&&num<=499) 
        {
            num = num - 400;
            str = str +"CD";
            transit(num,str);
        }
      if(num>=500&&num<=899)
      {
          num = num - 500;
          str = str + "D";
          transit(num,str);
      }
      if(num>=900&&num<=999)
      {
          num = num - 900;
          str = str + "CM";
          transit(num,str);
      }
        if(num>=1000)
      {
          num = num - 1000;
          str = str + "M";
          transit(num,str);
      }
}
    string intToRoman(int num) {
        string s = "";
        transit(num,s);
        return s;
    }
};
```
思路非常简单无脑。
