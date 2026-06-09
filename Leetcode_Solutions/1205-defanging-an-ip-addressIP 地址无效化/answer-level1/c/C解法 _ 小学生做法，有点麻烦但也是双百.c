### 解题思路
k用于记录遍历到了第几个'.'

### 代码

```c
char * defangIPaddr(char * address){
    int i=0;
    //int j=0;
    int k=0;
    
    //while(address[j]!='\0') j++;
    char* res=(char*)malloc((strlen(address)+7)*sizeof(char));
    while(address[i]!='\0')
    {
        if(address[i]=='.')
        {
            res[i+2*k]='[';
            res[i+2*k+1]='.';
            res[i+2*k+2]=']';
            k++;
        }
        else
        {
            res[i+2*k]=address[i];
        }
        i++;
    }
    res[i+6]='\0';
    return res;
}
```