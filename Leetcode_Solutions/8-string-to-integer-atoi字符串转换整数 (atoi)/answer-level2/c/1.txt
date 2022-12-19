```
int myAtoi(char * str)
{
    int len = strlen(str);
    if(len > 60 && *str > 0)
       return INT_MAX;
    else if(len > 60 && *str == '-')
        return INT_MIN;
    int a[100] = {0};
    int i = 0;
    int flag = 1,sum = 0,ID = 0;  //flag 用来记录正负
    while(*str)
    {
        if(i == 0 && (*str == '-' || *str == '+') && ID == 0)     //判断负号是否出现在第一个数字前
        {
            if(*str == '-')
                flag = -1;
            ++ID;
        }
            
        else if(*str >= '0' && *str <= '9')     //遇到数字存入a
            a[i++] = *str - '0';
        else if(i == 0 && !(*str >= '0' &&*str  <= '9') && *str != ' ')  //当第一个字符为非数字非符号非空格时退出循环 
            break;
        else if(i == 0 && !(*str >= '0' &&*str  <= '9') && *str == ' ' && ID != 0) //判断 " -42"这种情况
            break;
        else if(i != 0 && !(*str >= '0' &&*str  <= '9')) //非首位出现非数字非符号退出
            break;
            
        ++str;
    }
    if(i == 0)       //当第一个字符为非数字非符号
        return 0;

    int ret = i;
    for(int j = 0; j < ret; ++j)
    {
        sum += a[j] * pow(10,i-1);
        if(sum == INT_MIN && flag == 1)
            return INT_MAX;
         else if(sum == INT_MIN && flag == -1)
             return INT_MIN;
        --i;
    }
    sum *= flag;   //用来决定输出的正负
    return sum;
    
}
```
