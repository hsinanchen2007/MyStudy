这里的单词指的是连续的不是空格的字符，也就是说单词可以不是字母（如：逗号）。
```
int countSegments(char * s){
    if (s == NULL || s[0] == '\0') return 0;
    int word_sum = 0;
    int start = 0;//用来判断一个单词是否开始
    for (int i = 0; s[i]; ++i) {
        if (start) {
            if (isblank(s[i]))  start = 0, ++word_sum;
        }else{
            if (!isblank(s[i])) start = 1;
        }
    }
    return (start ? word_sum+1 : word_sum);//遇到结尾符
}
```
