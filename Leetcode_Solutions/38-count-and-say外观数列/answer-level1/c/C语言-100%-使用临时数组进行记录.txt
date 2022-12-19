### 解题思路
临时数组temp用来保存数据，关键字符key用来记录当前的字符，count记录当前字符的个数；当字符发生改变或者到达字符串结尾的时候将数据key以及count存入temp中，最后拷贝到输出结果数组res中并返回。

### 代码

```c
char * countAndSay(int n){
    char *res,*temp;
    res=malloc(sizeof(char)*5000);
    temp=malloc(sizeof(char)*5000);
    res[0]='1';
    res[1]='\0';
    int i,j,count;
    char *p,key;
    for(int i=1;i<n;i++)
    {
        j=0,count=0;
        p=res;
        key=res[0];
        while(*p!='\0')
        {
            if(*p==key)
                count++;
            else{
                temp[j++]=count+'0';
                temp[j++]=key;
                key=*p;
                count=1;
            }
            p++;
        }
        temp[j++]=count+'0';
        temp[j++]=key;
        temp[j]='\0';
        strcpy(res,temp);
    }
    return res;
}
```