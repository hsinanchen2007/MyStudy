```

bool buddyStrings(char * A, char * B){
int len1=strlen(A),len2=strlen(B);
    int i,j=0,count=0,dex[2]={0};
    char temp;
    if(len1!=len2)
        return 0;
    int num[27],max=0;
    memset(num,0,27);
    for(i=0;i<len1;i++)
    {
        if(A[i]!=B[i]){
           count++;
            if(count>2)
                return 0;
            dex[j++]=i;
        }
        num[A[i]-'a']++;
        if(num[A[i]-'a']>max);
        max=num[A[i]-'a'];
    }
    if(count==0&&max>=2)
        return 1;
    else if(count==2)
    {temp=A[dex[0]];
    A[dex[0]]=A[dex[1]];
    A[dex[1]]=temp;
    if(strcmp(A,B)==0)
        return 1;}
      return 0;
}
```