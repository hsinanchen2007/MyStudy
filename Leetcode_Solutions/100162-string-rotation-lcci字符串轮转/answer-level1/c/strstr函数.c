### 解题思路
学习到的字符串操作
1.建立数组的时候要+1 字符串有'\0'收尾
2.char *strstr(const char *str1, const char *str2);
找出str2字符串在str1字符串中第一次出现的位置（不包括str2的串结束符）。返回该位置的指针，如找不到，返回空指针。

### 代码

```c
bool isFlipedString(char* s1, char* s2){

    if(strlen(s1) != strlen(s2)) return false;

    int len=strlen(s1);
    char* temp = (char*)malloc(sizeof(char) * (2*len+1));

    strcpy(temp, s2);
    strcat(temp, s2);

    if(strstr(temp, s1) != NULL) return true;
    else return false;
}
```