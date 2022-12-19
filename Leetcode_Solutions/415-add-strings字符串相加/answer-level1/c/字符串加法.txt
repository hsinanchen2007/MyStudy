重要步骤 容易忽略，一定要记得

### 代码

```c
char * addStrings(char * num1, char * num2){
    int length1=strlen(num1),length2=strlen(num2),length;
    int i=length1-1, j=length2-1 ,num, tmp=0;  //tmp作用是 记录进一
    length=length1>length2? length1+1 :length2+1;
    int k=length-1;   //索引作用
    char *new_string=(char *)calloc(length+1,sizeof(char));
    new_string[0]='0'; new_string[length]='\0'; //要不是过不了

    for(;i>=0||j>=0||tmp ;i--,j--)     //当进1的时候，下一步也必须执行
    {
        num=(i>=0?num1[i]-'0':0)+(j>=0?num2[j]-'0':0)+tmp;
        tmp=0;
        if(num>9)
        {
            tmp=1;
            num=num-10;
        }
        new_string[k--]=num+'0';
    }
    if(new_string[0]=='0')   //整体要左移一位，由于没有进一
    {
        for(i=0;i<length-1;i++)
            new_string[i]=new_string[i+1];
        new_string[length-1]='\0';   //关键字符串
    }
    return new_string;

}
```