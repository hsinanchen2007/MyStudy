### 解题思路
1, 极端情况，数组长度小于等于1， 返回0
2. 对于数组进行快速排序。
3. 存在两种最小值的可能，一种直接就是minValue = （最大值-最小值），
4. 另外一种就是找到一个中间值，比这个小的+k， 比这个大的-K；
5. 此时的
5.      realMin = min(a[0] + K, a[i] - K); 
6.      realMax = max(a[Asize-1] -K, a[i-1] + K);
7.      如果 (realMax - realMin) < minValue, 则更新 minValue = (realMax - realMin);

### 代码

```c
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int smallestRangeII(int* A, int ASize, int K){
    if (ASize <= 1) {
        return 0;
    }
    qsort(A, ASize, sizeof(int), compare);
    int min = A[0];
    int max = A[ASize - 1];
    int res = max - min;
    //printf("init %d, %d, %d\n",min, max, res);
    for (int i = 1; i < ASize; i++) {
        //printf("check a:%d,%d\n", i, A[i]);
        int tmpMax = (max - K) > (A[i-1] + K) ? (max - K) : (A[i - 1] + K) ;
        int tmpMin = (min + K) > (A[i] - K) ? (A[i] - K) : (min + K) ;
        //printf("check min:%d, max:%d\n", tmpMax, tmpMin);
        if ((tmpMax - tmpMin) < res) {
            res =  (tmpMax - tmpMin);
        }
        //printf("res:%d\n", res);
    }
    return res;
}
```