### 解题思路
calloc函数会自动将内存初始化为0
![image.png](https://pic.leetcode-cn.com/3ce85ce64195e0fb684ed3ecaeb9237ed21f3a4cb4704f1da87624ffac0572e9-image.png)

### 代码

```c
char* replaceSpace(char* s){
    int len;
    char *str = NULL;
    char *temp = NULL;

    len = strlen(s);

    /* 长度加 '\0' */
    str = (char *)calloc(3*len + 1, sizeof(char));
    if (NULL == str)
        return NULL;

    temp = str;
    
    while (*s)
    {
        if (*s == ' ')
        {
            *str++ = '%';
            *str++ = '2';
            *str++ = '0';
        }
        else
            *str++ = *s;
            
        s++;
    }

    return temp;
}
```