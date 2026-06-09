##思路：
- 如果k=1，直接顺序赋值；
- 如果k!=1,前面n-k个数是等差数列，后面的k个数作海螺式分配
比如若n = 7, k = 4；
先依次排列1, 2, 3, 4, 5, 6, 7；
前三个数排等差数列1，2，3，差都是1；
后面四个数还能有三个不同的差值，就取2，3，4作为差；
第一个取7，和前一个数差为4；
第二个取4，和前一个数差为3；
第二个取6，和前一个数差为2；
第二个取5，和前一个数差为1；
```
int* constructArray(int n, int k, int* returnSize){
    int* a = malloc(n * sizeof(int));
    memset(a, 0, n * sizeof(int));
    if(k == 1){
        for(int i = 0; i < n; i++)
            a[i] = i + 1;
    }
    else{
        for(int i = 0; i < n - k; i ++)
            a[i] = i + 1;//前面等差数列已排好
        a[n - k] = n;
        int m = -1;
        for(int i = n - k + 1; i < n; i++){
            a[i] = a[i - 1] + m * (n - i);
            m = -m;
        }
    }
    *returnSize = n;
    return a;
}
```
