```c
int arrangeCoins(int n){
    int i = 0;

    while (1){
        n -= i;
        if (n < i + 1)
            break;
        i++;
    }
    return i;
}
```