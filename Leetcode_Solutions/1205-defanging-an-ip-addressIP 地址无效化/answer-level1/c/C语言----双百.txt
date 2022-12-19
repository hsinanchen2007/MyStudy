### 解题思路
此处撰写解题思路

### 代码

```c
char * defangIPaddr(char * address){
int n=strlen(address);
int i,j=0;
for(i=0;i<n;i++)
if(address[i]=='.')
j++;
n=n+j*2;j=0;
char*str=(char*)malloc(sizeof(char)*(n+1));
for(i=0;i<strlen(address);i++){
    if(address[i]=='.'){
        str[j++]='[';
        str[j++]='.';
        str[j++]=']';
    }
    else{
        str[j++]=address[i];
    }
}
str[n]='\0';
return str;
}
```