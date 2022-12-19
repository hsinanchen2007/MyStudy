int myAtoi(char *str)
{
    int i = 0, flag = 1;
    unsigned long value = 0;
    
    while(i < strlen(str))
    {
        if(str[i] == ' ')
        {
            i++;
        }
        else
        {
            break;
        }
    }
    
    if(i == strlen(str))
    {
        return 0;
    }
    
    if(str[i] == '-')
    {
        flag = -1;
        i++;
    }
    else if(str[i] == '+')
    {
        flag = 1;
        i++;
    }
    else if(str[i] > '9' || str[i] < '0')
    {
        return 0;
    }

    while(i < strlen(str))
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            value = value * 10 + str[i] - '0';
            if(value >= ((1l << 31)))
            {
                if(value == (1l << 31))
                {
                    if(flag == 1)
                    {
                        return ~(1l << 31);
                    }
                }
                else
                {
                    if(flag == 1)
                    {
                        return ~(1l << 31);
                    }
                    else
                    {
                        return (1l << 31);
                    }
                }
            }
            i++;
        }
        else
        {
            break;
        }
    }
    
    return value * flag;
}

