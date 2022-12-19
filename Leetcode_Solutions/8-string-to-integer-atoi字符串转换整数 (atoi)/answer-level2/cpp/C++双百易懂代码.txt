### 解题思路
将字符串拆分成三部分，第一部分是数字之前的字符，第二部分是数字，第三部分是数字后面直接丢弃的字符


### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int num=0;          //转换后的数字
        int i=0;            //数组下标
        bool key=true;      //标记是否为负数
        for(;i<str.length();i++)        //检查第一部分的字符
        {
            if(str[i]==' ') continue;       //如果是空格，跳过   
            else
                if(str[i]=='-'||str[i]=='+')    //如果是正负符号
                {
                    str[i]=='-'?key=false:key=true; //修改标记
                    i++;                            //数组下标后移一位到第一个数字（如果是数字的话）
                    break;                          //结束第一部分字符的判断
                }
                else
                {
                    if(str[i]>='0'&&str[i]<='9')    //如果是数字，结束第一部分的判断
                        break;
                    else                            //不是以上任何字符，返回0
                        return 0;
                }
        }

        for(;i<str.length();i++)    //检查第二部分的字符（数字部分）
        {
            if(str[i]>='0'&&str[i]<='9')    //如果是数字符号
            {
                if(JOSL(num,((int)(str[i])-(int)('0')),key))    //首先进行越界判断
                    return key?INT_MAX:INT_MIN;
                    
                num=(num*10)+((int)(str[i])-(int)('0'));    
            }
            else        //如果不是数字符号，结束第二部分字符的检查
            {
                break;
            }
        }
        //第三部分字符因为直接丢弃所以无需检查
        return key?num:-num;    //返回转换后的数字
    }

private:
    bool JOSL(int num,int add,bool key)  //越界判断
    {
        if(key)
        {
            if(num<INT_MAX/10)
            {
                return false;
            }   
            else
            {
                if(num==INT_MAX/10)
                {
                    if(add<INT_MAX%10)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    return true;
                }
            }
        }
        else
        {
            num=-num;
            add=-add;
            if(num>INT_MIN/10)
            {
                return false;
            }
            else
            {
                if(num==INT_MIN/10)
                {
                    if(add>INT_MIN%10)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    return true;
                }
            }
        }
    }
};
```