1、求出字符串的长度；
2、假设字符串的重复周期是1~len/2；
3、依次判断字符串的重复周期是1~len/2时，是否重复。是，结束整个循环。否，继续下一次迭代。

bool repeatedSubstringPattern(char * s){
    int len = 0;
    int i, j;
    if(s == NULL)
        return true;
    while(s[len] != 0)
    {
        len++;
    }

    for( i = 1; i <= (len / 2); i++)
    {
        if(( len % i) != 0 )
            continue;
        for( j = 0; j < len; j++)
        {
            if(s[j] != s[j % i])
                break;
        }
        if(j == len)
            return true;
    }
    return false;
}

