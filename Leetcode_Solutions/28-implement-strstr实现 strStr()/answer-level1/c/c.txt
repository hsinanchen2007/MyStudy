### 解题思路
此处撰写解题思路
1、只考虑needle长度为0情况；
2、只考虑hay_leg-nee_leg循环就行，不需要进行hay_leg长度的循环；

### 代码

```c
int strStr(char * haystack, char * needle){
    int i = 0, j = 0;
    int hay_leg = strlen(haystack);
    int nee_leg = strlen(needle);

    if(!nee_leg)
    {
        return 0;
    }

    //不用考虑所有长度，只考虑hay_leg-nee_leg就行
    for(i = 0; i <= (hay_leg - nee_leg); i++)
    {
        if(haystack[i] == needle[0])
        {
            for(j = 1; j < nee_leg; j++)
            {
                if(haystack[i + j] != needle[j])
                {
                    break;
                }
            }

            if(j == nee_leg)
            {
                return i;
            }
        }
    }

    return -1;
}
```