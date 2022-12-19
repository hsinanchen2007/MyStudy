先从小到大排序，然后把负数变号，如果负数个数<K，循环k次直接累加返回序列和，如果负数个数>K，判断（K-负数个数）是奇数还是偶数，若为偶数直接累加返回序列和，若为奇数再次排序，把最小数的变成负数，然后累加返回序列和。
```
int cmp(const void* a,const void* b){
    return *(int*)a>*(int*)b;
}
int largestSumAfterKNegations(int* A, int ASize, int K){
    qsort(A,ASize,sizeof(int),cmp);
    int sum=0;
    for(int i=0;A[i]<0;i++){
        A[i]=-A[i];
        K--;
        if(K==0){
            for(int i=0;i<ASize;i++)
                sum+=A[i];
            return sum;
        }
    }
    if(K%2==0){
        for(int i=0;i<ASize;i++)
            sum+=A[i];
        return sum;
    }
    qsort(A,ASize,sizeof(int),cmp);
    sum=-A[0];
    for(int i=1;i<ASize;i++)
        sum+=A[i];
    return sum;
}


```
