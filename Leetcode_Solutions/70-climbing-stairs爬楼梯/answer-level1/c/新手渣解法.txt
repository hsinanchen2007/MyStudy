递归法（普通斐波那契数列会超时，设一个变量存历史值）

```
int climbStairsB(int, int*);

int climbStairs(int n){
    int* mem = (int*)calloc(n, sizeof(int));
    int cnt = climbStairsB(n, mem);
    free(mem);
    return cnt;
}

int climbStairsB(int n, int* mem){
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (mem[n - 1] > 0) return mem[n - 1];
    mem[n - 1] = climbStairsB(n - 1, mem) + climbStairsB(n - 2, mem);
    return mem[n - 1];
}
```

迭代法
```
int climbStairs(int n){
    if (n == 1) return 1;
    if (n == 2) return 2;
    int last1 = 1, last2 = 2;
    int cnt = 0;
    for (int i = 2; i < n; i++){
        cnt = last1 + last2;
        last1 = last2;
        last2 = cnt;
    }
    return cnt;
}
```
