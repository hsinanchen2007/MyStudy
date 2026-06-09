```c
int* sumZero(int n, int* returnSize){
    short i;
    int *a=(int*)malloc(n*sizeof(n));
    for(i=0;i<n/2;i++) a[i]=i+1;
    for(i=n/2;i<n;i++) a[i]=-a[i-n/2];
    if(n%2==1) a[n-1]=0;
    *returnSize=n;
    return a;
}
```