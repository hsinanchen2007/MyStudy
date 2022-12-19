1、判断num1和num2是否非空，有空的话即可返回。
2、判断两者之一是否为0，如果存在。返回0。
3、两个字符串分别反序。
4、从最低位开始做乘法的操作，并记录溢出情况。
5、注意最高位的溢出需要单独处理。
int reverseStr(char* p)
{
    int len, i, j;
    char tmp;
    if(p == NULL)
        return 0;
    i = 0;
    len = 0;
    while(p[len] != '\0')
    {
        len++;
    }
    j = len -1;
    while(i<j)
    {
        tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
        i++;
        j--;
    }
    return len;
}

char * multiply(char * num1, char * num2){
    int len1, len2;
    int i,j;
    char* result;

    int curVal, flag, preflag;
    int resLen = 0;
    if((num1 == NULL) || (num2 == NULL))
        return NULL;
    
    len1 = reverseStr(num1);
    len2 = reverseStr(num2);
    if((len1 == 1) && (num1[0] == '0'))
        return "0";
    if((len2 == 1) && (num2[0] == '0'))
        return "0";
    resLen = len1+len2;
    result = (char*)malloc(resLen+10);
    memset(result, '0', resLen+10);
    flag = 0;
    preflag = 0;
    printf("strlen %d %d %d\n", len1, len2, resLen);
    for(i = 0; i < len1; i++)
    {
        flag = 0;
        preflag = 0;
        for(j = 0; j < len2; j++)
        {
            curVal = (num2[j] - '0') * (num1[i] - '0');
            curVal = curVal + preflag + (result[i+j] - '0');
            flag = curVal / 10;
            curVal = curVal % 10;
            result[i+j] = curVal + '0';
            preflag = flag;

        }
        if(preflag != 0)
        {
            // add preflag to i+j
            curVal = result[i+j] - '0';
            curVal += preflag;
            flag = curVal / 10;
            curVal = curVal % 10;
            result[i+j] = curVal + '0';
            
        }
    }
    if(preflag != 0)
    {
        result[i+j-1] = preflag + '0';
        result[i+j] = '\0';
    }
    else
    {
        result[i+j-1] = '\0';
    }
    printf("i and j is %d %d preflag is %d\n", i,j, preflag);
    result[i+j] = '\0';
    reverseStr(result);
    return result;
    
}

