### 解题思路
只要长度不同就返回最长的，要是长度和内容都完全相同则返回-1，要是长度相同但有不相同的内容则返回这个长度。
### 代码

```c
int findLUSlength(char * a, char * b){
    if(strlen(a)==strlen(b))
    {
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]!=b[i])
            {
                return strlen(a);
            }
        }
        return -1;
    }
    else
    {
        return strlen(a)>strlen(b)?strlen(a):strlen(b);
    }
    return 0;
}
```