### 解题思路
此处撰写解题思路

### 代码

```c
char* replaceSpace(char* s){
int i,count=0,k=0;
for(i=0;i<strlen(s);i++)
if(s[i]==' ')
count++;
int n=strlen(s)+count*2;
char*ret=(char*)malloc(sizeof(char)*(n+1));
for(i=0;i<strlen(s);i++){
if(s[i]==' '){
    ret[k++]='%';
    ret[k++]='2';
    ret[k++]='0';
}
else
ret[k++]=s[i];
}
ret[n]='\0';
return ret;
}
```