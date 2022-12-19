**统计前一个为空格且自身不是空格的数量即可。(注意s[0])**
```c
int countSegments(char * s)
{
    int cnt = 0, i, len = strlen(s);
    for(i = 0; i < len; i++){
        if((i == 0 || s[i-1] == ' ') && s[i] != ' ')
            cnt++;
    }
    return cnt;
}
```