### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) {
        bool E=false;    //记录e
        bool dot=false;  //记录小数点
        bool keyF=false;    //是否存在符号位
        bool numKey=false;  //是否有数字存在

        int i=0;        //数组下标

        for(;i<s.length();i++)
        {
            if(!(s[i]>='0'&&s[i]<='9')) //第一个位置只能出现正负号，小数点或者数字，如果是空格则跳过
            {
                if(s[i]!=' ')   //如果不是空格，检查字符
                {
                    if(s[i]=='+'||s[i]=='-')    //如果是正负号
                    {
                        keyF=true;
                    }
                    else                
                    {
                        if(s[i]=='.')   //如果是小数点
                        {
                            dot=true;
                        }
                        else        //不是数字，正负号，空格，小数点
                        {
                            return false;
                        }
                    }
                    i++;
                    break;
                }
            }
            else        //否则说明这个字符是数字，直接结束
            {
                numKey=true;
                break;
            }
        }

        if(keyF)    //如果存在符号位
        {
            if(s[i]=='e') return false; //数字部分第一个位置不能是 e
        }

        for(;i<s.length();i++)
        {
            if(!(s[i]>='0'&&s[i]<='9')) //如果不是数字
            {
                if(s[i]=='.')           //如果是小数点
                {
                    if(dot)             //如果已经存在小数点
                        return false;

                    if(E)               //如果已经存在e，说明小数点在e的后面，返回假
                        return false;

                    dot=true;
                }
                else
                    if(s[i]=='e')           //如果是科学计数符号e
                    {
                        if(E||i+1>=s.length())  //如果已经存在E，返回假，同时e不能是最后一个字符
                            return false;
                        if(s[i-1]=='.'&&numKey==false)     //如果前一位是小数点且没有数字存在
                            return false;
                        if(i+1<s.length())  //e后面一位可以是符号位
                        {
                            if(s[i+1]=='+'||s[i+1]=='-')
                            i++;    //跳过符号位
                        }
                        else    //否则说明e是最后一个字符，此时必定为假
                        {
                            return false;
                        }
                        numKey=false;   //e后面必须有数字，所以重新记为false
                        E=true;
                    }
                    else
                        //都不是，说明是其它字符
                        break;
            }
            else
                numKey=true;    //否则就存在数字
        }

        for(;i<s.length();i++)  //如果后面的都是空格，就可以全部忽略
        {   
            if(s[i]!=' ')   //只要不是空格，返回假
            return false;
        }

        return numKey;  //只有存在数字的情况下才返回真
    }
};
```