### 解题思路
数字 0 1 2 3 4 5 6 7 8 9 
列数 1 2 3 4 5 6 7 8 9 10
字母 A B C D E F G H I J 

列数的n对应(十进制)数字中的n-1,（十进制）数字的m对应（二十六进制）字母的‘A’+m
所以操作就是 列数 转 十进制数字 转 二十六进制字母
### 代码

```c
char * convertToTitle(int n){
    int lenght = 0, temp = n;
    while (temp)
    {
        lenght++;
        temp = (temp - 1) / 26;
    }

    char *result = (char*)malloc(sizeof(char)*(lenght + 1));
    result[lenght] = 0;

    while (lenght--)
    {
        result[lenght] = (n - 1) % 26 + 'A';
        n = (n - 1) / 26;
    }
    return result;
}
```