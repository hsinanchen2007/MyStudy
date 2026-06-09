### 解题思路
方法：按位依次处理进位。

1.创建新数组用于存储计算结果，考虑到可能进位，新数组长度比两个原数组中最长的大一位。「strlen不计算'\0',故+2」；
2.新数组除'\0'外初始化为'0';
3.循环处理:
    .每次累加到新数组上，；两种进位的特殊情况分别处理;
4.返回值处理:
    .由于预留一个可能的进位，若无进位。返回首地址的下一个地址，有进位则直接返回首地址;

### 代码

```c
char * addBinary(char * a, char * b){
    int alen = strlen(a);
    int blen = strlen(b);
    int length = (alen > blen) ? alen + 2 : blen + 2;
    char* c = (char*)malloc(length*(sizeof(char)));
    memset(c, '0', length);
    c[length - 1] = '\0';
    for(length -= 2; length > 0; length--){
        int an = (alen > 0) ? a[--alen] - '0' : 0;
        int bn = (blen > 0) ? b[--blen] - '0' : 0;
        c[length] += (an + bn);
        if(c[length] == '2'){
            c[length] = '0';
            c[length - 1] ++;
        }
        else if(c[length] == '3'){
            c[length] = '1';
            c[length - 1] ++;
        }
    }
    if(c[0] == '0')
        c++;
    return c;
}
```
