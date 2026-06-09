char * addBinary(char * a, char * b){
    int len_a = strlen(a), len_b = strlen(b);
    char* ret, *l, *s;
    int len_l, len_s, i, flag = 0, temp, len;

    if(len_a > len_b)
    {
        l = a;
        s = b;
        len_l = len_a;
        len_s = len_b;
    }
    else
    {
        l = b;
        s = a;
        len_l = len_b;
        len_s = len_a;
    }

    ret = (char* )malloc((len_l + 2) * sizeof(char));

    len = len_l;
    len_l--;
    len_s--;
    i = len_l;

    while(len_s >= 0)
    {
        temp = l[len_l--] - '0' + s[len_s--] - '0' + flag;

        if(temp >= 2)
        {
            ret[i--] = temp - 2 + '0';
            flag = 1;
        }
        else
        {
            ret[i--] = temp + '0';
            flag = 0;
        }
    }

    while(len_l >= 0)
    {
        temp = l[len_l--] - '0' + flag;

        if(temp >= 2)
        {
            ret[i--] = temp - 2 + '0';
            flag = 1;
        }
        else
        {
            ret[i--] = temp + '0';
            flag = 0;
        }
    }

    if(flag == 1)
    {
        for(i = len; i > 0; i--)
        {
            ret[i] = ret[i-1];
        }

        ret[0] = '1';
        ret[len+1] = '\0';
    }
    else
    {
        ret[len] = '\0';
    }

    return ret;
}