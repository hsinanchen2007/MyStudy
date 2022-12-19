就是改变比较规则，然后使用位运算进行统计1的个数
```
int onefigure(int num){
    int fi = 0;
    while(num != 0){
        if((num & 1) == 1){
            fi++;
        }
        num >>= 1;
    }
    return fi;
}
int cmp(const void * a, const void * b){
    int c = *(int *)a,d = *(int*)b;
    int f1 = 0, f2 = 0;
    f1 = onefigure(c);
    f2 = onefigure(d);
    if(f1 == f2){
        return c - d;
    }
    return f1 - f2;
}
int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    qsort(arr,arrSize,sizeof(int), cmp);
    return arr;
}
```
