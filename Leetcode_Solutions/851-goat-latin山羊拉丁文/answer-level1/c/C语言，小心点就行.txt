执行用时：4 ms
已经战胜 100.00 % 的 c 提交记录
```c
char * toGoatLatin(char * S){
    char *start = S;
    char *end;
    int cnt = 0;
    char * r = malloc(11250);
    memset(r, 0, 11250);
    int idx = 0;
	int len = strlen(S);
    for(int i = 0; i <= len; i++, S++)
    {
        if( (*S == ' ') || (*S == '\0') )
        {   
            cnt++;
            end = S-1;
            if( 
                (*start == 'a') || (*start == 'e') || (*start == 'i') || (*start == 'o') || (*start == 'u') ||
                (*start == 'A') || (*start == 'E') || (*start == 'I') || (*start == 'O') || (*start == 'U')
            )
            {
                for(; start <= end; start++)
                    r[idx++] = *start;
                r[idx++] = 'm';
                r[idx++] = 'a';
            }
            else 
            {
                char ch = *start;
                start++;
                for(; start <= end; start++)
                    r[idx++] = *start;
                r[idx++] = ch;
                r[idx++] = 'm';
                r[idx++] = 'a';
            }
            for (size_t j = 0; j < cnt; j++)
            {
                r[idx++] = 'a';
            }
            if(*S == ' ')
                r[idx++] = ' ';
            start = S+1;
        }
    }
    return r;
}
```