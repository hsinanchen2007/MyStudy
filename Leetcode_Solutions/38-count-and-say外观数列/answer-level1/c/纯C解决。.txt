基本思路：一个中间数组用来保存数据，一个key用来记录当前的字符，count记录个数
代码应该是非常清晰易懂的，自行看一下。
稍微注意一下存count和key有两个条件，一个是字符改变的时候，一个是走到末尾了。
```
char * countAndSay(int n){
    char *mark=(char *)malloc(sizeof(char)*5000);
    char *temp=(char *)malloc(sizeof(char)*5000);
    mark[0]='1';
    mark[1]='\0';//结束标志
    int i,count,j;
    char key,*p;
    for(i=1;i<n;i++)//迭代次数
    {
        j=0;
        key=mark[0];
        count=0;
        p=mark;
        while(*p!='\0')
        {
            if(*p==key)//计数
                count++;
            else{
                temp[j++]=count+'0';//先存计数器
                count=1;
                temp[j++]=key;//再存关键字
                key=*p;
            }
            p++;

        }
        temp[j++]=count+'0';//先存计数器
        temp[j++]=key;//再存关键字
        temp[j]='\0';
        strcpy(mark,temp);
    }
    return mark;
}

```
