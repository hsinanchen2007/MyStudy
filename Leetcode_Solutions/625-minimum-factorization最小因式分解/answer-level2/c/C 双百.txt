### 解题思路
C 双百

### 代码

```c
int smallestFactorization(int a){
    if (a/10 == 0) {
        printf("-1");
        return a;
    }
    int* res_arr = (int*)malloc(20*sizeof(int));
    int arrLen = 0;
    int tmp = a;
    while (tmp/10 > 0) {
        int j = 0;
        for (j = 9; j >= 2; j--) {
            if (tmp%j == 0) {
                res_arr[arrLen] = j;
                arrLen++;
                break;
            }
        }
        printf("%d ", j);
        if (j == 1) {
            printf("0");
            return 0;
        }
        tmp = tmp / j;
    }
    long long res = 0;
    int i = arrLen - 1;
    while (i >= 0) {
        if (res_arr[i] < tmp) {
            res = res*10 + res_arr[i];
            i--;
        }
        else {
            res = res*10 + tmp;
            tmp = 11; 
        }
    }
    if (tmp != 11) {
        res = res*10 + tmp;
    }
    if (res > INT_MAX) {
        printf("1");
        return 0;
    }
    return res;
}
```