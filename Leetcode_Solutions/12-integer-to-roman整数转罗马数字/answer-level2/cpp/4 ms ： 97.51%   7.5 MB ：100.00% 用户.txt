### 解题思路
解码函数```trans(int num)```.
注意这里不光是基本的```1 5 10 50 100....```的解码，还有就是```4 9 40 90.....```的解码。
这里可以采用枚举来实现，作者采用switch来进行解码。
其他译码存在多个重复的情况，比如```3译码成III```.用函数multiple_str（string s,int mul)来实现。
此外4 和9的特殊情况在主要函数里面实现。

intToRoman函数里面，设置处理因子factor，处理不同的情况，比如3894.首先factor设置为1000.用num/factor得到各个位上的因子.
如果因子为9，那么直接利用解码函数进行翻译，（当然这里不存在9000的情况，可以忽略）。如果因子大于5却不等于9.这个时候应该是表示成5*factor+后面的。
比如894==500+300+90+4；
同样的道理，当因子小于5时，分两种情况，等于4和不等于4.

### 代码

```cpp
class Solution {
 string trans(int num)
    {
/*
字符          数值
i             1
v             5
x             10
l             50
c             100
d             500
m             1000
*/
        switch (num) {
        case 1:return "I";
        case 5:return "V";
        case 10:return "X";
        case 100:return "C";
        case 50:return "L";
        case 500:return "D";
        case 1000:return "M";
        case 4:return "IV";
        case 9:return "IX";
        case 40:return "XL";
        case 90:return "XC";
        case 400:return "CD";
        case 900:return "CM";
        default:return "";
        }
    }
    string multiple_str(string s, int multiple)
    {
        string str;
        for (int i = 0; i < multiple; i++)
            str += s;
        return str;
    }
public:
    string intToRoman(int num) {
        int factor = 1000;
        string str = "";
        while (num != 0)
        {
            int multiple = num / factor;
            if (multiple >= 5)
            {
                if (multiple == 9)
                {
                    str += trans(9 * factor);
                    num -= 9 * factor;
                }
                    
                else
                {
                    str += trans(5 * factor);
                    num -= 5 * factor;
                }
                    
            }
            else 
            {
                if (multiple == 4) {
                    str += trans(4 * factor);
                }
                else
                {
                    str += multiple_str(trans(factor), multiple);
                }
                num -= multiple * factor;
                factor /= 10;
            }
        }
        return str;
    }
};
```