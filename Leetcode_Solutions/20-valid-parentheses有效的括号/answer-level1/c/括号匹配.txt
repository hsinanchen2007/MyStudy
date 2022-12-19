### 解题思路
1.先求出串的长度len
2.创建一个一样大小的串str
3.遍历s串，其中
    a:是左括号，直接入栈str
    b:是右括号，如果和栈中匹配，出栈；否则，入栈
4.最后看栈中是否只有'\0'，是则匹配

### 代码

```c
bool isValid(char * s){
    int len = 1,k=0;
    char *str;
    while(*s++!='\0')len++;
    s-=len;
    str = (char*)malloc(sizeof(char)*len);
    str[k]=s[0];
    for(int i=1;i<len;i++){
        if(k>-1&&(s[i]==')'&&str[k]=='('||s[i]==']'&&str[k]=='['||s[i]=='}'&&str[k]=='{'))k--;
        else str[++k] = s[i];
    }
    if(str[0]=='\0')return true;
    return false;
}
```