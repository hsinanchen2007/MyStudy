### 解题思路
此处撰写解题思路

### 代码

```c
char * defangIPaddr(char *address){
    int i=0,j=0,ls=strlen(address);
    char s[ls+7];
    char *x=s;
    s[ls+6]='\0';

    for(;*(address+i)!='\0';i++){
        if(*(address+i)!='.') s[j]=*(address+i);
        else{
            s[j++]='[';
            s[j++]='.';
            s[j]=']';
        }
        j++;
    }
    return x;
}
```