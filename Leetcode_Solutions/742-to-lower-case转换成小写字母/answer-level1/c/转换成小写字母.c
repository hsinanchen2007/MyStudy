### 解题思路


### 代码

```c
char * toLowerCase(char * str){
    for(int i = 0;str[i] != '\0';i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return str;
}
```