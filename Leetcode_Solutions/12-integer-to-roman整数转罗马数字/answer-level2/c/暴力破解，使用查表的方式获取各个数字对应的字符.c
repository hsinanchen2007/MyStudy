### 解题思路
暴力破解，使用查表的方式获取各个数字对应的字符，跳过了各种分支判断；

### 代码

```c
char * intToRoman(int num){

    char* strTbl[4][10] = {
                            {"","M","MM","MMM","","","","","",""},
                            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                            {"","I","II","III","IV","V","VI","VII","VIII","IX"}
                        };
    unsigned int strlen[] = {0,1,2,3,2,1,2,3,4,2};

    unsigned int tempNum = num;
    unsigned int temp[4];
    unsigned int index;

    char* str = malloc(100);
    unsigned int strIndex = 0;
    unsigned int strIndexTemp = 0;

    for(index = 0; index < sizeof(temp)/sizeof(temp[0]); index++)
    {
        temp[sizeof(temp)/sizeof(temp[0]) - index - 1] = tempNum%10;
        tempNum = tempNum/10;
        //printf("%d", temp[sizeof(temp)/sizeof(temp[0]) - index - 1]);
    }

    for(index = 0; index < sizeof(temp)/sizeof(temp[0]); index++)
    {
        if (temp[index] == 0)
        {
            continue;
        }
        for (strIndexTemp = 0; strIndexTemp < strlen[temp[index]]; strIndexTemp++)
        {
            //printf("%c",strTbl[index][strIndexTemp]);
            str[strIndex++] = *(strTbl[index][temp[index]] + strIndexTemp);
        }
    }
    str[strIndex] = '\0';
    return str; 
}
```