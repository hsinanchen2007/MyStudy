### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3607b44b3a1944281090d0d9b6d19c26f55dd0d4648b30bed381c9bfcfcf2525-image.png)

### 代码

```c
char* replaceSpace(char* s)
{
    int i = 0;
    int space = 0;
    int len = strlen(s);
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
        {
            space++;
        }
        i++;
    }
    s = (char* )realloc(s, sizeof(char) * (len  + 2 * space + 1));              //为s重新申请内存空间
    int newlen = len + 2 * space;
    s[newlen--] = '\0';
    i = len -1;
    while(i >= 0)
    {
         if(s[i] != ' ')
         {
             s[newlen--] = s[i];
         }
         else
        {
             s[newlen--] = '0';
             s[newlen--] = '2';
             s[newlen--] = '%';
        }
        i--;
    }
    return s;
}
```