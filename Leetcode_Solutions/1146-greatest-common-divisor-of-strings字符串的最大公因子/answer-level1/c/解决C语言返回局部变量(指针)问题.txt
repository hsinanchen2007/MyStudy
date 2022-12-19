### 解题思路
使用static修饰，分配在静态内存区
还有一种方法使用malloc分配内存（堆中）需要手动free，麻烦.

### 代码

```c
int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a % b);
}
char * gcdOfStrings(char * str1, char * str2){
    int i;
    static char str[1010];
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int l = gcd(l1,l2);
    memcpy(str,str1,l);
    str[l] = '\0';
    for(i = 0;i < l1 - 1;i += l){
        if(memcmp(str,str1 + i,l))
            break;
    }
    if(i < l1 - 1){
        str[0] = '\0';
        return str;
    }
    for(i = 0;i < l2 - 1;i += l){
        if(memcmp(str,str2 + i,l))
            break;
    }
    if(i < l2 - 1){
        str[0] = '\0';
        return str;
    }
    return str;
}
```