用long int型 存储数字
先找到第一个不为空格的字符，判断是否位正负标志位（循环从符号下一个位置开始）或者数字（循环起点）；否则返回 0；
从k开始遍历字符串，不为数字则break；
a对于int溢出时，返回对应的最值；
不溢出，强转类型。

class Solution {
public:
    int myAtoi(string str) {
     long int a=0;
        int fh=0;
        int k=0;
         for(int i=0;i<str.size();i++)
         {
             k=i;
             if (str[i]==' ')  continue;
             if(str[i]=='-')  {fh=1;k++;break;}
               if(str[i]=='+')  {fh=0;k++;break;}
             if('0'<=str[i]&&str[i]<='9') break;
             return 0;
       
         }
        for(;k<str.size();k++)
        {
           
            if ('0'<=str[k]&&str[k]<='9')
            {
                if(a>INT_MAX/10){
                    if (fh==1)
                    return INT_MIN;
                    else return INT_MAX;
                }
           
              a=a*10+static_cast<int>(str[k]-'0');  
            }
             else break;
        }
        if (fh==1)
            a=-a;
         if(a>INT_MAX) return INT_MAX;
        if(a<INT_MIN) return INT_MIN;
            return static_cast<int>(a);
    }
};