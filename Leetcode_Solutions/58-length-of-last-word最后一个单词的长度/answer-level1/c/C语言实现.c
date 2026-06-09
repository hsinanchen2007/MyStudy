注意先过滤末尾的空格字符串，如果遍历完整个字符串未出现一个字母字符，下标变成-1，返回值需要加1；若出现一个不为空格的字符，从该字符位置开始到出现空格或遍历完整个字符串结束
```
int lengthOfLastWord(char * s){
    int len = strlen(s);
    int i = len - 1;
    
    while(i>=0 && s[i]==' ') i--;   //过滤掉末尾的空格字符
    len = i;
    for(; i>=0 && s[i] != ' '; i--);

    return (i<0 ? len+1 : len-i);
}
```