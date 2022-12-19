1. 输出数组中有k个不同整数，则差的最大绝对值也为k
2. 奇偶下标交替使用最新的gap,gap的取值范围为[1,k]
3. gap满足k种后，停止循环，后面的gap全部为1就行
```
int* constructArray(int n, int k, int* returnSize){
    int *result=(int *)malloc(sizeof(int)*n);
    int i,gap;
    result[0]=1;
    for(i=1,gap=k;i<=k;i++,gap--){
        result[i]=i%2==1? result[i-1]+gap:result[i-1]-gap;
    }
    for (int i = k + 1; i < n; i++) {
        result[i] = i + 1;
    }
    *returnSize=n;
    return result;
}
```
