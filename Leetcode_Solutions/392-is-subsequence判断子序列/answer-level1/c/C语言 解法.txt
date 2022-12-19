![QQ截图20200229184723.jpg](https://pic.leetcode-cn.com/ba44d3ea759aad3f96803755cc09441a8fe589d21f90ce5ed792071d9c0bb693-QQ%E6%88%AA%E5%9B%BE20200229184723.jpg)

### 代码

```c
bool isSubsequence(char * s, char * t){
    char* p;
    char* q = s;
    if(*q == '\0') // 如果s为空，直接返回true
        return true;
    for(p=t;*p!='\0';p++)
    {
        if(*p == *q)
        {
            q++;
            if(*q == '\0')
            {
                return true;
            }
        }
    }
    return false;
}
```