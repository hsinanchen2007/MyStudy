### 解题思路

这么短的代码居然是4ms的，为啥不是0ms的，时间都去哪了呢。。。。。

我把加减法换成异或运算还是4ms，真是让人费解啊。。。。

### 代码

```c
char findTheDifference(char * s, char * t)
{
    int i;
    char c=0x00;
    for(i=0;i<strlen(s);i++)
    {
        c+=t[i]-s[i];
    }
    return c+t[i];
}
```