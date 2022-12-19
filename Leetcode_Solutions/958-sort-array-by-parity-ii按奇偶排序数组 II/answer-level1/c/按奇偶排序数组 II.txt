```
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    //生成一个大小为ASize的数组
    int *ret = (int *)malloc(sizeof(int)* ASize);
    *returnSize = ASize;
    int k1 = 0;
    int k2 = 1;
    for (int i=0;i<ASize;i++){
        if (A[i] % 2 == 0){
            ret[k1] = A[i];
            k1 = k1 + 2;
        }else{
            ret[k2] = A[i];
            k2 = k2 + 2;
        }
    }
    return ret;
}
```
