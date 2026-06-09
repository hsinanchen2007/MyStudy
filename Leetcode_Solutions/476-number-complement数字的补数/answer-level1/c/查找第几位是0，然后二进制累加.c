```
int findComplement(int num){
    int n=0,i=0;
    while(num){
        int j=num&1;
        if(j==0)
            n+=pow(2,i);
        i++;
        num>>=1;
    }
    return n;
}


```
