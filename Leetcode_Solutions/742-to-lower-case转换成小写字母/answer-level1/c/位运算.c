### 解题思路
大写变小写，|= 0b00100000；
小写变大写，&= 0b11011111；
大小写互换，^= 0b00100000；

### 代码

```c
/* 位运算 */
char * toLowerCase(char * str){
    char *t = str;
    while(*t != '\0'){
        if(*t >= 'A' && *t <= 'Z')
            *t |= 0b00100000;
        t++;
    }
    return str;
}

// /* ASCII */
// char * toLowerCase(char * str){
//     char *t = str;
//     while(*t != '\0'){
//         if(*t >= 'A' && *t <= 'Z')
//             *t += 32;               // 'a' - 'A' == 0x20
//         t++;
//     }
//     return str;
// }
```