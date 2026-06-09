```
int romanToInt(char *s)
{
    int slen = strlen(s);
    int sum = 0;
    int count1 = 0, count2 = 0;
    /*--------------定义一个整数数组--------------- */
    int *arr = (int *)malloc(sizeof(int) * slen);
    /*--------------判断字符串是否合法------------- */
    for (size_t i = 0; i < slen; i++)
    {
        if (s[i] == 'I')
        {
            count1++;
        }
        else if (s[i] == 'X')
        {
            count1++;
        }
        else if (s[i] == 'C')
        {
            count1++;
        }
        else if (s[i] == 'M')
        {
            count1++;
        }
        else if (s[i] == 'V')
        {
            count2++;
        }
        else if (s[i] == 'D')
        {
            count2++;
        }
        else if (s[i] == 'L')
        {
            count2++;
        }
    }
    /*-----------判断次数------------------------ */
    if ((count1 > 3) || (count2 > 1))
    {
        printf("Input ERROR");
    }
    else
    {
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
        for (size_t i = 0, j = 1; i < slen - 1, j < slen; i++, j = i + 1)
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
    }
    return sum;
    free(arr);
}
```
