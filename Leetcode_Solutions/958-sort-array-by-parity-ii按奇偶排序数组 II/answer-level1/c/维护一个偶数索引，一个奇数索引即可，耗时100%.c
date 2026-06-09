```
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    //动态申请一块内存
    int *ret = (int *)malloc(sizeof(int) * ASize);
    memset(ret, 0, sizeof(int) * ASize);
    //维护一个偶数索引，一个奇数索引
    int idxji = 1;
    int idxou = 0;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            ret[idxou] = A[i];
            idxou += 2;
        } else {
            ret[idxji] = A[i];
            idxji += 2;
        }
    }
    * returnSize = ASize;
    return ret;
}
```
