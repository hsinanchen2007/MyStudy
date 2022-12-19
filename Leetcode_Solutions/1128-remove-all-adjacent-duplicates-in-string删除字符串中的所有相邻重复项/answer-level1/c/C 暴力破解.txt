没想到啥好的方法，直接暴力破解了；耗费时间比较久的一点就是
S[length] = '\0';
这行没有加， 导致返回的字符串老是长度不对；
```
void updat (char *s, int *length, int idx)
{
    int i;
    for (i = idx; i < *length - 2; i++){
        s[i] = s[i + 2];
    }
}

void delchar (char* s, int *length)
{
    int idx = 0;
    while (idx < (*length - 1)) {
        if (s[idx] == s[idx + 1]) {
            updat(s, length, idx);
            *length -=2;
            if(idx > 0) {
                idx--;
            }
        } else {
            idx++;
        }
    }
    return;
}

char * removeDuplicates(char * S){
    int length = 0;
    if (NULL == S) {
        return NULL;
    }
    while (NULL != S[length]) {
        length++;
    }
    delchar(S,&length);
    S[length] = '\0';
    return S;
}
```
