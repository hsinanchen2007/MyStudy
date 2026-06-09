
int searchValue(char s)
{
    int ret;
    switch(s)
    {
        case 'I':
            ret = 1;
            break;

        case 'V':
            ret = 5;
            break;

        case 'X':
            ret = 10;
            break;

        case 'L':
            ret = 50;
            break;

        case 'C':
            ret = 100;
            break;

        case 'D':
            ret = 500;
            break;

        case 'M':
            ret = 1000;
            break;   
    }
    return ret;
}

int romanToInt(char * s){
    int ret = 0;
    while(*s)
    {
        int curValue = searchValue(*s);
        int nextValue = searchValue(*(s+1));
        if(curValue<nextValue)  
        {
            ret += nextValue - curValue;
            s++;
        }
        else
        {
            ret += curValue;
        }
        s++;
    }
    return ret;
}

