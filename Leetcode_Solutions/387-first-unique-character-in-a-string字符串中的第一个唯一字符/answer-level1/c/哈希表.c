### 解题思路
    哈希 ~ ~ ~
### 代码

```c
int firstUniqChar(char * s){
    int map[128] = {0};
    int i,len = strlen(s);
    for(i = 0;i < len;i++) map[s[i] - 'a']++;
    for(i = 0;i < len;i++)
        if(map[s[i] - 'a'] == 1) 
            return i;
    return -1;
}
```