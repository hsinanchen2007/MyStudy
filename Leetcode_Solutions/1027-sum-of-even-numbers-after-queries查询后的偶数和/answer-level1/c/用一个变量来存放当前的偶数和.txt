执行用时 :0 ms, 在所有C提交中击败了100.00%的用户
内存消耗 :22.8 MB, 在所有C提交中击败了100.00%的用户

先计算原数组中偶数和，然后再判断。

tmp = (A[queries[i][1]] + queries[i][0]);


如果__A[queries[i][1]]__是偶数：

tmp是奇数：从偶数和中减掉A[queries[i][1]]

tmp是偶数：偶数和 加上 queries[i][0]



如果__A[queries[i][1]]__是奇数：

tmp是奇数：啥也不做

tmp是偶数：偶数和 加上 tmp

```
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int i = 0;
    int sum_even = 0; //偶数和
    for (i = 0; i < ASize; ++i) {
        if (!(A[i] % 2)) sum_even  += A[i];
    }
    int *my_out = (int *)malloc(sizeof(int) * ASize);
    int tmp = 0;
    for (i = 0; i < queriesSize; ++i) {
        tmp = (A[queries[i][1]] + queries[i][0]);
        if (A[queries[i][1]] % 2) { //奇数
            if (!(tmp % 2)) sum_even += tmp;
        }else{
            if (tmp % 2)    sum_even -= A[queries[i][1]];
            else            sum_even += queries[i][0];
        }
        A[queries[i][1]] = tmp;
        my_out[i] = sum_even;
    }
    * returnSize = ASize;
    return my_out;
}
```



