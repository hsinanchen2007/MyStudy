### 解题思路

通过递归的方式，一次比一次小地进行查找，将拼接后的字符串拼合返回。

### 代码

```cpp
class Solution
{
public:
    string intToRoman(int num)
    {
        if (num >= 900)
        {
            //M
            string tmp = "";
            while (num >= 1000)
            {
                tmp += "M";
                num -= 1000;
            }
            if (num >= 900)
            {
                tmp += "CM";
                num -= 900;
            }
            return tmp + intToRoman(num);
        }
        else if (num >= 400)
        {
            string tmp = "";
            if (num >= 500)
            {
                tmp += "D";
                num -= 500;
            }
            else
            {
                tmp += "CD";
                num -= 400;
            }
            return tmp + intToRoman(num);
        }
        else if (num >= 90)
        {
            string tmp = "";
            while (num >= 100)
            {
                tmp += "C";
                num -= 100;
            }
            if (num >= 90)
            {
                tmp += "XC";
                num -= 90;
            }
            return tmp + intToRoman(num);
        }
        else if (num >= 40)
        {
            string tmp = "";
            if (num >= 50)
            {
                tmp += "L";
                num -= 50;
            }
            else
            {
                tmp += "XL";
                num -= 40;
            }
            return tmp + intToRoman(num);
        }
        else if (num >= 9)
        {
            string tmp = "";
            while (num >= 10)
            {
                tmp += "X";
                num -= 10;
            }
            if (num >= 9)
            {
                tmp += "IX";
                num -= 9;
            }
            return tmp + intToRoman(num);
        }
        else if (num >= 4)
        {
            string tmp = "";
            if (num >= 5)
            {
                tmp += "V";
                num -= 5;
            }
            else
            {
                tmp += "IV";
                num -= 4;
            }
            return tmp + intToRoman(num);
        }
        else
        {
            string tmp = "";
            while (num > 0)
            {
                tmp += "I";
                num -= 1;
            }
            return tmp;
        }

        return "NULL";
    }
};
```