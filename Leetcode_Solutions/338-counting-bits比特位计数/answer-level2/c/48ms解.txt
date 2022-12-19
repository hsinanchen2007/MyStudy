二进制，每次进位之后，比进位之前多一个
```
int* countBits(int num, int* returnSize){
    int* a=(int*)malloc((num+1)*sizeof(int));
    *returnSize=num+1;
    a[0]=0;
    int t=1;
    for(int i=1;i<=num;i++){
        if(i==t)
            t*=2;
        a[i]=a[i-t/2]+1;
    }
    return a;
}
```
