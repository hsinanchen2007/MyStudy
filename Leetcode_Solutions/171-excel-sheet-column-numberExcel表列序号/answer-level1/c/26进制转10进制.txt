### 解题思路
1. 进制转换

### 代码

```c
int titleToNumber(char * s){
    int num = 0;

    while (*s != '\0')
    {
        num = num * 26 + (*s - 'A' + 1);
        s++;
    }
    return num;
}
```