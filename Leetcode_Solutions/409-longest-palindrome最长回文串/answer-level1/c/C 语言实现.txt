1、遍历寻找每个字符在整个字符串出现的次数；
2、出现的次数*2/2就是该字符串支持组成的回文串长度。
3、所有字母支持的回文串长度加起来，并判断是否还有剩余字符。有的话，再加一。

int longestPalindrome(char * s){
    int *newArray;
    char* str = s;
    int i;
    int offset = 0;
    int len = 0;
    int flag = 0;
    if(s == NULL)
        return 0;
    newArray = (int*)malloc(sizeof(int) * 52);
    for( i = 0; i < 52; i++)
    {
        newArray[i] = 0;
    }
    i = 0;
    
    while(str[i] != '\0')
    {
        if((str[i] >= 'a') && (str[i] <= 'z'))
        {
            offset = str[i] - 'a';
            newArray[offset] += 1;
        }
        else if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            offset = 26 + str[i] -'A'; 
            newArray[offset] += 1;
        }
        else
        {
            
        }
        i++;
    }
    // string length
    len = 0;
    for( i = 0; i < 52; i++ )
    {
        len += (newArray[i] >> 1);
        if((newArray[i] % 2) == 1)
            flag = 1;
    }
    free(newArray);
    return len * 2 + flag;
}

```


int longestPalindrome(char * s){
    int *newArray;
    char* str = s;
    int i;
    int offset = 0;
    int len = 0;
    int flag = 0;
    if(s == NULL)
        return 0;
    newArray = (int*)malloc(sizeof(int) * 52);
    for( i = 0; i < 52; i++)
    {
        newArray[i] = 0;
    }
    i = 0;
    
    while(str[i] != '\0')
    {
        if((str[i] >= 'a') && (str[i] <= 'z'))
        {
            offset = str[i] - 'a';
            newArray[offset] += 1;
        }
        else if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            offset = 26 + str[i] -'A'; 
            newArray[offset] += 1;
        }
        else
        {
            
        }
        i++;
    }
    // string length
    len = 0;
    for( i = 0; i < 52; i++ )
    {
        len += (newArray[i] >> 1);
        if((newArray[i] % 2) == 1)
            flag = 1;
    }
    free(newArray);
    return len * 2 + flag;
}


```
