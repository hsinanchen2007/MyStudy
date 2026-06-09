### 解题思路
1、先使用一个26位整形数组记录所有字符出现次数；
2、通过数组内数字是否为零判断，依次从小到大，再从大到小循环存放到字符数组；
3、注意存放字符数组要多分配一位空间，存放结束字符'\0'；

### 代码

```c
char * sortString(char * s){
    int char_counter[26];
    int len = strlen(s);
    char * sort_str=(char *)malloc(sizeof(char)*(len+1));
    int i = 0, j = 0;
    for(i = 0; i < 26; i++)
    {
        char_counter[i] = 0;
    }
    for(i = 0; i < 26; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(('a'+i)==s[j])
            {
                char_counter[i]++;
            }
        }
    }
    i = 0;
    while(i < len)
    {
        for(j = 0; j < 26; j++)
        {
            if(char_counter[j] != 0)
            {
                sort_str[i++]='a' + j;
                char_counter[j]--;
            }

        }
        for(j = 25;j >= 0; j--)
        {
            if(char_counter[j] != 0)
            {
                sort_str[i++]='a' + j;
                char_counter[j]--;
            }
        }
    }
    sort_str[i] = '\0';
    return sort_str;
}
```