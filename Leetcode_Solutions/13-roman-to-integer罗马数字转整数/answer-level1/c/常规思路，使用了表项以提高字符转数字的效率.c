### 解题思路
常规思路，使用了表项以提高字符转数字的效率

### 代码

```c
int romanToInt(char * s){
    int numTotal = 0;
    int temp;
    int index;
    int strLen = strlen(s);
    int lastNum = 0;
    int romansToNum[] = {   0,0,100,500,0,
                            0,0,0,1,0,
                            0,50,1000,0,0,
                            0,0,0,0,0,
                            0,5,0,10,0};

    while ( index < strLen )
    {
        temp = romansToNum[(int)(s[strLen - index -1] - 'A')];
        if (temp < lastNum)
        {
            numTotal -= temp;
        }
        else
        {
            numTotal += temp;
        }

        lastNum = temp;
        index++;
    }

    return numTotal;
}
```