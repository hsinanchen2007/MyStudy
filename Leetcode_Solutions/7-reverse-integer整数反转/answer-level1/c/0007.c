```
int reverse(int n) {
    long num = n;

    int flag = num > 0 ? 1 : -1;
    num = num * flag;

    long result = 0;

    while (num) {
        result = result * 10 + num % 10;
        num = num / 10;
    }

    if (result < 0 || result != (int) result) {
        return 0;
    } else {
        return result * flag;
    }
}
```
