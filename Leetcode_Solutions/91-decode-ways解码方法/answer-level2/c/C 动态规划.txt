```
int numDecodings(char * s){
    int len=strlen(s);
    int **status=(int **)malloc(sizeof(int *)*2);
    status[0]=(int *)calloc(len+2,sizeof(int));
    status[1]=(int *)calloc(len+2,sizeof(int));
    status[1][1]=1;
    int *one=status[0]+2;
    int *two=status[1]+2;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0')one[i]=0;
        else one[i]=one[i-1]+two[i-1];
        if(i==0||s[i-1]=='0'||s[i-1]>'2'||(s[i-1]=='2'&&s[i]>'6'))two[i]=0;
        else two[i]=one[i-2]+two[i-2];
        if(one[i]==0&&two[i]==0)return 0;
        //printf("%d   %d %d\n",i,one[i],two[i]);
    }
    int ret=one[len-1]+two[len-1];
    free(status[0]);
    free(status[1]);
    free(status);
    return ret;
}
```