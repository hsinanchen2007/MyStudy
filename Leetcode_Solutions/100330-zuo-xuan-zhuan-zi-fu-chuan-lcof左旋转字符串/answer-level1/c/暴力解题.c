### 解题思路
此处撰写解题思路

### 代码

```c
char* reverseLeftWords(char* s, int n){
    int lenght = strlen(s);
    int temp = 0;
    char *array = (char *)malloc(sizeof(char) * (lenght + 1));//字符串以'\0'结尾，所以长度多加1
    memset(array, 0, sizeof(char) * (lenght + 1));

    for(int i = lenght - n; i < lenght; i++)
    {
        array[i] = s[temp++];
    }
    for(int i = 0; i < lenght - n; i++)
    {
        array[i] = s[temp++];
    }



    array[temp] = '\0';
    return array;
}
```