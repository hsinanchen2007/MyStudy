```
int repeatedNTimes(int* A, int ASize){

    int hash[10000]={0};
    for(int i=0;i<ASize;i++)
    {
        hash[A[i]]++;
    }
    int res=0;
    for(int i=0;i<10000;i++)
    {
        if(hash[i]==ASize/2)
        {
            res=i;
            break;
        }
    }
    return res;
    
}
```
