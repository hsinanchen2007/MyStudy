**用一个数组保存s中每个字符的出现次数，然后遍历时输出第一个次数为1的索引即可。**
```c
int firstUniqChar(char * s){
    int i, len = strlen(s);
    int p[26];
    memset(p, 0, sizeof(int) * 26);
   
    for(i = 0; i < len; i++){
        p[s[i] - 'a']++;
    }
    for(i = 0; i < len; i++){
        if(p[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}
```