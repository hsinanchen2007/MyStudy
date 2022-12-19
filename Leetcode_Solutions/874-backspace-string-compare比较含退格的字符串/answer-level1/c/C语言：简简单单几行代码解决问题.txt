利用双指针，如果遇到#，前面的指针就往前移

```
bool backspaceCompare(char * s_str, char * t_str)
{
    if (s_str == NULL && t_str == NULL) return true;
    if (s_str == NULL                 ) return false;
    if (                 t_str == NULL) return false;
    
    int i = 0;
    int j = 0;
    while (s_str[j]) {
        if (s_str[j] == '#') {
            if (i > 0) --i;
        }else s_str[i++] = s_str[j];
        ++j;
    } 
    s_str[i] = 0;

    i=j=0;
    while (t_str[j]) {
        if (t_str[j] == '#') {
            if (i > 0) --i;
        }else t_str[i++] = t_str[j];
        ++j;
    } 
    t_str[i] = 0;
    return !strcmp(s_str ,t_str);
}
```
