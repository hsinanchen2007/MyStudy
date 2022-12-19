### 解题思路
因为题干未说只有小写字母，所以用了tolower。

### 代码

```c
char firstUniqChar(char* s){
    if(strlen(s) == 0){
        return " ";
    }
    int hash[26] = {0};
    int i;
    for(i = 0; i < strlen(s); i++){
        hash[tolower(s[i]) - 'a']++;
    }
    for(i = 0; i < strlen(s); i++){
        if(hash[tolower(s[i]) - 'a'] == 1){
            return s[i];
        }
    }
    return " ";
}
```