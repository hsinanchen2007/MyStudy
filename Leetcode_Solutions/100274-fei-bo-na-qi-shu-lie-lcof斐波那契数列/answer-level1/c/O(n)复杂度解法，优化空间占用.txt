```
int fib(int n){
    if (n < 2) {
        return n;
    }

    int ret[2] = {0, 1};
    int temp;

    for (int i = 2; i <= n; i++) {
        temp = ret[0] + ret[1];
        ret[i % 2] = temp % 1000000007;
    }

    return ret[n%2];
}
```
