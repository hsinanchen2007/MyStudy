### 解题思路
从后往前找第一个单词，统计其长度即可。

### 代码

```c
int lengthOfLastWord(char * s){
    if(!s || s == "")
        return 0;
    int len = strlen(s);
    int i, j;
    for(i = len - 1; i >= 0 && s[i] ==' '; i--);
    for(j = i; j >= 0 && s[j] != ' '; j--);
    return i - j;
}