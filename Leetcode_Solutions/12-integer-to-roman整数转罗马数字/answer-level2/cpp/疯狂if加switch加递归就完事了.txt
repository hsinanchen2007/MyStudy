### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        if(num<10)
         {
             switch (num)
             {
                 case 1: return "I";
                 case 2: return "II";
                 case 3: return "III";
                 case 4: return "IV";
                 case 5: return "V";
                 case 6: return "VI";
                 case 7: return "VII";
                 case 8: return "VIII";
                 case 9: return "IX";
                 case 10: return "X";
             }
         }
        if(num<=100)
        {
            int n=num/10;
            switch (n)
            {
                case 1: return "X"+intToRoman(num%10);
                case 2: return "XX"+intToRoman(num%10);
                case 3: return "XXX"+intToRoman(num%10);
                case 4: return "XL"+intToRoman(num%10);
                case 5: return "L"+intToRoman(num%10);
                case 6: return "LX"+intToRoman(num%10);
                case 7: return "LXX"+intToRoman(num%10);
                case 8: return "LXXX"+intToRoman(num%10);
                case 9: return "XC"+intToRoman(num%10);
                case 10: return "C"+intToRoman(num%10);
            }
        }
        if(num<=1000)
        {
            int n=num/100;
            switch (n)
            {
                case 1: return "C"+intToRoman(num%100);
                case 2: return "CC"+intToRoman(num%100);
                case 3: return "CCC"+intToRoman(num%100);
                case 4: return "CD"+intToRoman(num%100);
                case 5: return "D"+intToRoman(num%100);
                case 6: return "DC"+intToRoman(num%100);
                case 7: return "DCC"+intToRoman(num%100);
                case 8: return "DCCC"+intToRoman(num%100);
                case 9: return "CM"+intToRoman(num%100);
                case 10: return "M"+intToRoman(num%100);
            }
        }

    else
        {   
            int n=num/1000;
            switch (n)
             {
                case 1: return "M"+intToRoman(num%1000);
                case 2: return "MM"+intToRoman(num%1000);
                case 3: return "MMM"+intToRoman(num%1000);
             }
        }
        return "";
    }
};
```