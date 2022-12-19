### 解题思路
常规思路

### 代码

```c
char* replaceSpace(char* s){
    int n=strlen(s);
    char* num=(char*)malloc(sizeof(char)*(n+1)*3);
    int cnt=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==' ')
        {
            num[cnt++]='%';
            num[cnt++]='2';
            num[cnt++]='0';
        }
        else
        {
            num[cnt++]=s[i];
        }
    }
    num[cnt]='\0';
    return num;
}
```