
![image.png](https://pic.leetcode-cn.com/c8e903ce7ae8f81a8a5cf44f5a270b86a4c9bd2e3f1283ea99977bf730e08ac0-image.png)

>避免动态空间的使用，通过指针修改了原参
>时间复杂度： O(n) 空间复杂度： O(1)

思路：遍历数组将ascii大写范围映射到ascii小写范围
大写范围：'A'~'Z' 0x40~0x5B
小写范围：'a'~'z' 0x60~0x7B
区域距离：'a'-'A'/'b'-'B'/...
映射方法：+=0x20 / |=0x20
遍历方法：for/while/...


#### 0x01 while循环&*str直接指向 0ms
```c
char * toLowerCase(char * str){
    char *new=str;
    while(*str){if(*str>0x40&&*str<0x5B)*str+=0x20;str++;}
    return new;
}
```
#### 0x02 while循环&&str[i]数组访问 0ms
```c
char * toLowerCase(char * str){
    int i=0;
    while(str[i]){if(str[i]>0x40&&str[i]<0x5B)str[i]+=0x20;i++;}
    return str;
}
```
**Plus版(问号表达式)**
```c
char * toLowerCase(char * str){
    int i=0;
    while(str[i]){(str[i]>0x40&&str[i]<0x5B)?str[i++]+=0x20:i++;}
    return str;
}
```
#### 0x03 for循环&*str直接指向 4ms
```c
char * toLowerCase(char * str){
    char *new=str;
    for(;*str!='\0';str++)if(*str>='A'&&*str<='Z')*str+=0x20;
    return new;
}
```
#### 0x04 for循环&str[i]数组访问 4ms
```c
char * toLowerCase(char * str){
    for(int i=0;str[i]!='\0';i++)if(str[i]>='A'&&str[i]<='Z')str[i]=str[i]+32;
    return str;
}
```
结论：while循环效率高出不少