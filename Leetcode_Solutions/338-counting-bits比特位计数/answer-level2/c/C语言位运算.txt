beat 95.75%

```
int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int *r = (int *)malloc((num+1) * sizeof(int));
    memset(r, 0, (num+1) * sizeof(int));
    for (int i = 1; i<=num; i++) {
        r[i] += r[i&(i-1)] + 1;
    }
    return r;
}
```
