```
char arr0[5000];
char arr1[5000];
char * countAndSay(int n){
    if(n<1 || n>30)return "";
    memset(arr0,0,sizeof(arr0));
    memset(arr1,0,sizeof(arr1));
    arr0[0] = '1';
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            //printf("arr0 = %s\n",arr0);
            int len = strlen(arr0);
            char c = arr0[0];
            int num = 1;
            int k=0;
            arr1[0]=num+'0';
            arr1[1]=c;
            for(int j=1;j<len;j++)
            {
                if(arr0[j]==c)
                {
                    num++;  
                }
                else
                {
                    arr1[k++]=num+'0';
                    arr1[k++]=c;
                    //printf("****k=%d\n",k);
                    //printf("****arr1=%s\n",arr1);
                    c=arr0[j];
                    num = 1;
                }
            }
            arr1[k++]=num+'0';
            arr1[k++]=c;
        }
        else
        {
            //printf("arr1 = %s\n",arr1);
            int len = strlen(arr1);
            char c = arr1[0];
            int num = 1;
            int k=0;
            arr0[0]=num+'0';
            arr0[1]=c;
            for(int j=1;j<len;j++)
            {
                if(arr1[j]==c)
                {
                    num++;  
                }
                else
                {
                    arr0[k++]=num+'0';
                    arr0[k++]=c;
                    c=arr1[j];
                    num = 1;
                }
            }
            arr0[k++]=num+'0';
            arr0[k++]=c;
        }
    }
    //printf("%s\n",arr0);
    //printf("%s\n",arr1);
    if(n%2==0)return arr1;
    else return arr0;
}
```
