方法:根据输入的字符串,转换成对应的整数数组

由于当数组元素为1,10,100时,只要右边的数组元素大于它,计算的时候就要减去它,我们可以根据这个特性来调整数组元素的正负号!

调整完成后,就可以求和求出最后结果!
```
int romanToInt(char *s)
{
    int slen = strlen(s);
    int sum = 0;
    /*--------------定义一个整数数组--------------- */
    int *arr = (int *)malloc(sizeof(int) * (slen));
    /*--------------转换成整数数组----------------- */
    for (size_t i = 0; i < slen; i++)
    {
        if (s[i] == 'I')
        {
            arr[i] = 1;
        }
        else if (s[i] == 'V')
        {
            arr[i] = 5;
        }
        else if (s[i] == 'X')
        {
            arr[i] = 10;
        }
        else if (s[i] == 'L')
        {
            arr[i] = 50;
        }
        else if (s[i] == 'C')
        {
            arr[i] = 100;
        }
        else if (s[i] == 'D')
        {
            arr[i] = 500;
        }
        else if (s[i] == 'M')
        {
            arr[i] = 1000;
        }
    }
    /*-----------调整数组元素的正负号--------------------------------- */
    for (size_t i = 0, j = 1; i <slen - 1, j < slen; i++, j = i + 1)
    {
        if (arr[i] == 1)
        {
            if (arr[i] < arr[j])
            {
                arr[i] = -1;
            }
        }
        if (arr[i] == 10)
        {
            if (arr[i] < arr[j])
            {
                arr[i] = -10;
            }
        }
        if (arr[i] == 100)
        {
            if (arr[i] < arr[j])
            {
                arr[i] = -100;
            }
        }
    }
    /*----------------求和---------------------------- */
    for (size_t i = 0; i < slen; i++)
    {
        sum = sum + arr[i];
    }
    
    
    return sum;
    free(arr);
}
```
