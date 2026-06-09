```
char * convertToTitle(int n){
    int b[100]={0};
    int N=0;
    while(n){
        n--;
        b[N++]=n%26;
        n/=26;
    }
    char* a=(char*)malloc(10000*sizeof(char));
    int j=0;
    for(int i=N-1;i>=0;i--)
        a[i]=b[j++]+'A';
    a[N]='\0';
    return a;
}


```
