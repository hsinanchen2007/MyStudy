### 解题思路
A~Z的ASCII值为65~90。
a~z的ASCII值为97~122.
也就是说，小写字母的ASCII值是其对应大写字母的ASCII值加上32。
代码如下

### 代码

```c
char * toLowerCase(char * str){
    char *p;
    p = str;
    for(;*p!='\0';p++)
    {
        if((int)*p < 91 && (int)*p > 64)
        {
            *p = (int)*p + 32;
        }
    }
    return str;
}
```