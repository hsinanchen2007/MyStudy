就是单纯的模拟加法的过程，不懂的欢迎留言
```
char * addStrings(char * num1, char * num2){
    int num,length,length1=strlen(num1),length2=strlen(num2),
    i=length1-1,sum=0,j=length2-1,k;
    if(length1>length2)
        length=length1+1;
    else
        length=length2+1;
    k=length-1;
    char *num3=(int *)malloc(sizeof(char)*(length+1));
    num3[0]='0';num3[length]='\0';
    while(i>-1||j>-1||sum)
    {
        num=(i>-1?num1[i]-'0':0)+(j>-1?num2[j]-'0':0)+sum;
        sum=0;
        if(num>9)
        {
            sum=1;
            num=num-10;
        }
        num3[k--]=num+'0';
        i--;
        j--;
    }
    if(num3[0]=='0')//左移一位
    {
        for(i=0;i<length-1;i++)
        num3[i]=num3[i+1];
        num3[length-1]='\0';
    }
    return num3;
}       
```
