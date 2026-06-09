### 解题思路
此处撰写解题思路

### 代码

```c
char * defangIPaddr(char * address){
    int i=0,j=0,addresslength,sign[4],num,m=0;
    char c[22],temp;
    char *a;
    a=malloc(22*sizeof(char));
    while(address[i]){
        if(address[i]=='.'){
            sign[j++]=i;
            c[i]=address[i];
        }
        else
            c[i]=address[i];
        i++;
    }
    i=0;
    j=0;
    while(c[i]){
        if(i==sign[j]){
            a[m++]='[';//printf("[");
            a[m++]=c[i];//printf("%c",c[i]);
            a[m++]=']';//printf("]");
            j++;
        }
        else{
            a[m++]=c[i];//printf("%c",c[i]);
        }
        i++;
    }
    a[m++]='\0';
    i=0;
    while(a[i]){
        printf("%c",a[i++]);
    }
    return a;
}
```如果您能看完那真是牛皮