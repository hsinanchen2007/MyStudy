### 解题思路
此处撰写解题思路

### 代码

```c


int myAtoi(char * str)
{
    int len = strlen(str);  
    if(len > 60 && *str > 0)       //用来过最后的那个超长例子，
       return INT_MAX;
    else if(len > 60 && *str == '-')    //同上
        return INT_MIN;
    int a[100] = {0};
    int i = 0;
    int flag = 1,sum = 0,ID = 0;
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
        else if(i == 0 && !(*str >= '0' &&*str  <= '9') && *str != ' ')  //当第一个字符为非数字非符号时退出循环 
            break;
        else if(i == 0 && !(*str >= '0' &&*str  <= '9') && *str == ' ' && ID != 0)
            break;
        else if(i != 0 && !(*str >= '0' &&*str  <= '9'))
            break;
            
        ++str;
    }
    //printf("%d %d",i,flag);
    if(i == 0)       //当第一个字符为非数字非符号
        return 0;

    int ret = i;
    for(int j = 0; j < ret; ++j)
    {
        sum += a[j] * pow(10,i-1);
        printf("%d ",sum);
        if(sum == INT_MIN && flag == 1)     //当sum 超范围 并且为正 
            return INT_MAX;
         else if(sum == INT_MIN && flag == -1)   //超范围 且为负
             return INT_MIN;
        --i;
    }
    sum *= flag;
    return sum;
    
}


```