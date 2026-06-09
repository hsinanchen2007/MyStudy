C语言实现，先过滤大写字母前面有小写字母的情况，再判断全是大写，或者全小写及首字母大写。
```
bool detectCapitalUse(char * word){
    int len = strlen(word);
    int i, capital = 0;
    for (i = 0; i < len; ++i) {
        if (word[i] < 'a' && capital++ < i) return false;
    }
    return capital == len || capital < 2;
}
```
