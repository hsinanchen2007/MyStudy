### 解题思路
使用计数器，strstr函数比对皆可，具体见代码注释。

### 代码

```c
//利用计数器0ms完成，逢L加一，逢A和P清空L计数;
#include <string.h>

bool checkRecord(char * s){
    int Absent = 0, Late = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == 'A'){
            Absent++;
            Late = 0;
            if(Absent > 1){
                return false;
            }
        }else if(s[i] == 'L'){
            Late++;
            if(Late > 2){
                return false;
            }
        }else if(s[i] == 'P'){
            Late = 0;
        }
    }
    return true;
}
```


```c
//利用strstr函数进行字符串查找实现，4ms，代码可读性较强;
#include <string.h>

bool checkRecord(char * s){
    int Absent = 0;
    char * str = NULL;
    for (int i = 0; i < strlen(s); i++){
        if(s[i] == 'A'){
            Absent++;
        }
    }
    str = strstr(s, "LLL");
    if(Absent > 1 || str != NULL){
        return false;
    }else{
        return true;
    }
}
```

```c
//第一次写的比较蠢的判断，4ms，忽略;
#include <string.h>

bool checkRecord(char * s){
    int Absent = 0, flag = 0;
    for (int i = 0; i < strlen(s); i++){
        if(s[i] == 'A'){
            Absent++;
        }
        if(s[i] == 'L' && flag == 0){
            flag = 1;
            continue;
        }
        if(s[i] != 'L'){
            flag = 0;
            continue;
        }
        if(s[i] == 'L' && flag == 1){
            flag = 2;
            continue;
        }
        if(s[i] == 'L' && flag == 2){
            flag = 3;
            break;
        }
    }
    if(Absent > 1 || flag == 3){
        return false;
    }else{
        return true;
    }
}
```