```
//遇到重复字符串后，将指针移到重复字符串的后面
int lengthOfLongestSubstring(char * s)
{
    int mark[128]; //记录某个字符上次出现的位置,ASCII码值作为索引,字符对应位置
    memset(mark, -1, sizeof(int) * 128);
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }
    if (strlen(s) == 1) {
        return 1;
    }
    int max = 1;
    int start = 0; //记录非重复子串的最左端位置
    int i = 0; //移动指针索引
    while (i < strlen(s)) {
        if (mark[s[i]] >= start) { //如果出现，说明该字符的位置大于或等于该字符
            max = max > (i - start) ?  max : (i - start);
            start = mark[s[i]] + 1; //更新无重复子串的左端位置
        }
        mark[s[i]] = i; //将当前字符的位置赋给位置表
        i++;  
    }
    max = max > (strlen(s) - start) ? max : (strlen(s) - start);
    return max;
}
```
