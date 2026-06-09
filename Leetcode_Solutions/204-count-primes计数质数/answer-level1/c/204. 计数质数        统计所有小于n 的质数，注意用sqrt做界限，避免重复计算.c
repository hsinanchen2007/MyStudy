### 解题思路
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

### 代码

```c
int countPrimes(int n){
    int i, j, k, prime, sq;

    if (n <= 2)
        return 0;
    k = 1;
    for (i = 3; i < n; i+=2) {
        sq = sqrt(i);
        for (j = 3; j <= sq; j+=2) {
            if (i%j == 0)
                break;
        }
        //printf("j=%d sq=%d\n", j, sq);
        if (j > sq)
            k++;
    }
    return k;
}
```