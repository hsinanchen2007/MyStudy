```
为什么没有反转字符串的库函数啊！！！！

bool isPalindrome(char * s){
    int i, len = strlen(s), j = 0, k = 0;
    if (len == 0)
        return true;
    char *str = (char*)malloc(sizeof(char) * len);

    for (i = 0; i < len; i++){
        if (!isalnum(s[i]))
            continue;
        else
            str[j++] = tolower(s[i]);
    }
    //str[j] = '\0';//为什么加上这个却不能通过？求大佬解惑
    char *t = (char*)malloc(sizeof(char) * (j / 2 + 1));
    for (i = j / 2 - 1; i >= 0; i--){
        t[k++] = str[i];
    }
    t[k] = '\0';
    if (abs(strncmp(t, str + (j / 2 + j % 2), j / 2)))
        return false;
    else
        return true;
}


```
