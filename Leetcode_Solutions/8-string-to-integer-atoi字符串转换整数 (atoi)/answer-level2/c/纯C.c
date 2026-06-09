纯C
```
int myAtoi(char * str){
    short ssSign = 0;
    long slInterget = 0;

    /* remove the rubbish blank space */
    for( ; *str == ' '; str++);

    /* record the sign */
    ssSign = (*str == '-') ? -1 : 1; // only consider the negative status
    if(*str == '+' || *str == '-')
    {
        str++;
    }

    /* get the integer */
    while((*str >= '0') && (*str <= '9'))
    {
        slInterget = slInterget * 10 + (*(str++) - '0');

        if((int)slInterget != slInterget) // is over length or not
        {
            return (ssSign == 1) ? INT_MAX : INT_MIN;
        }
    }

    slInterget = ssSign * slInterget;

    return slInterget;
}
```
