### 解题思路
此处撰写解题思路
s2+s2中包含s1, C++ string类型操作应该更简单
### 代码

```c
bool isFlipedString(char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2) {
        return false;
    }
    char *temp = malloc(2*len1+1);
    memset(temp,0,2*len1+1);
    strncpy(temp,s2,len1);
    strncat(temp,s2,len1);
    if(strstr(temp,s1)) {
        return true;
    }
    return false;
}
```