int myAtoi(char * str)
{
    int min = -2147483648, max = 2147483647, flag = 1;
    long long sum = 0;
    while(' ' == *str) str++;
    if(!(*str == '+' || *str == '-' || *str >= '0' && *str <= '9'))
        return 0;
    if('+' == *str)
    {
        str++;
    }
    else if('-' == *str)
    {
        flag = -1;
        str++;
    }
    if(!(*str >= '0' && *str <= '9')) return 0;
    while(*str >= '0' && *str <= '9')
    {
        sum = sum * 10 + *str - '0';
        str++;
        if(sum > max)
            return flag == 1 ? max : min;
    }
    return sum * flag;
}