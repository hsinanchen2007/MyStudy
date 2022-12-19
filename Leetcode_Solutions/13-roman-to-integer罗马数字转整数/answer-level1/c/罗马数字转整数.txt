### 解题思路

字符串从左到右遍历，如果遇到的是“C”、“X”、“I”，需要判断它后面的字符，然后一起计算数值，如果不是这几个字符，则直接加上所代表的数值即可

### 代码

```c
int romanToInt(char * s){

    int  result = 0;
    int len = strlen(s);
    if (len == 0)
        return 0;
    int index = 0;
    while(1)
    {
        if(index == len)
            break;
        if(s[index] == 'M')
           result += 1000;
        else if(s[index] == 'D') 
           result += 500;
        else if(s[index] == 'C')
        {
            if((index+1) == len)
                result += 100;
            else if((index + 1) < len)
            {
                if(s[index +1 ] == 'M')
                {
                    result += 900;
                    index = index +1;
                }
                else if(s[index +1 ] == 'D')
                {
                    result += 400;
                    index = index +1;
                }
                else
                   result += 100;
            }
        }
        else if(s[index] == 'L')
            result += 50;
        else if(s[index] == 'X')
        {
            if((index+1) == len)
                result += 10;
            else if((index+1) < len)
            {
                if(s[index + 1] == 'C')
                {
                    result += 90;
                    index = index +1;
                }    
                else if(s[index + 1] == 'L')
                {
                    result += 40;
                    index = index +1;
                }
                else
                    result += 10;
            }
        }
        else if(s[index] == 'V')
            result += 5;
        else if(s[index] == 'I')
        {
            if((index+1) == len)
                result += 1;
            else if((index+1) < len)
            {
                if(s[index + 1] == 'X')
                {
                    result += 9;
                    index = index +1;
                }    
                else if(s[index + 1] == 'V')
                {
                    result += 4;
                    index = index +1;
                }
                else
                    result += 1;
            }
        }
        index++;    
    }
    return result;
    
}


```