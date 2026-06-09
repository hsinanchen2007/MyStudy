```
char * reverseWords(char * str){
    if (str == NULL || str[0] == '\0') return str;
    int fast = 0, last = 0;
    while (str[fast] && str[fast] == ' ') ++fast; //找字符第一个非空格字符
    while (str[fast]) {
        for (last = fast; str[last] && str[last] != ' '; ++last); //找单词的最后一个字符
        for (int i = fast, j = last-1; i < j; ++i, --j) str[i] ^= str[j] ^= str[i] ^= str[j];//交换
        for (fast = last; str[fast] && str[fast] == ' '; ++fast); //找单词的第一个字符
    }
    return str;
}
```
