**筛就完事了**
```
int countPrimes(int n)
{
    if(n == 0 || n == 1)
        return 0;
    int *isPrime = (int*)malloc(sizeof(int) * n);
    memset(isPrime, 0, sizeof(int) * n);
    int i, j, cnt = 0;
    for(i = 2; i < n; i++){
        if(isPrime[i] == 0){
            cnt++;
            for(j = i + i; j < n; j += i){  //筛去i的倍数
                isPrime[j] = 1;
            }
        }
    }
    return cnt;
}
```