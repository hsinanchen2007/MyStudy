溢出的问题完全可以交给字符串去判断
```
int reverse(int x){
    char* max = "2147483647";
    char* min = "2147483648";
    char str[100];
    char temp;
    int sign;
    int res;
    int i,j,index;
    sprintf(str,"%d",x);
    int len = strlen(str);
    if(str[0] == '-'){
        sign = -1;
        for (i = 0; i < len-1; ++i)
            str[i] = str[i+1];
        str[i] = 0;
        len--;
    }
    else{
        sign = 1;
    }
    index = len-1;
    for (i = 0; i < len/2; ++i)
    {
        temp       = str[i];
        str[i]     = str[index];
        str[index--] = temp;
    }
    if (len > 10)
        return 0;
    else if(len == 10){
        if(sign == -1)
            for (i = 0; i < 10; ++i){
                if(str[i] < min[i]){
                    break;
                }
                if(str[i] > min[i]){
                    return 0;
                }
            }
        else{
            for (i = 0; i < 10; ++i){
                if(str[i] < max[i]){
                    break;
                }
                if(str[i] > max[i]){
                    return 0;
                }
            }
        }
    }
    res = atoi(str);
    return sign*res;
}
```
