```c
int maximum69Number (int num){
    int tmp1 = 1;
    int tmp2 = num;
    while (tmp2) {
        tmp1 *= 10;
        tmp2 /= 10;
    }
    tmp1 /= 10;
    tmp2 = num;
    while (tmp2) {
        if (tmp2 / tmp1 == 6) {
            num += 3 * tmp1;
            break;
        }
        tmp2 -= 9 * tmp1;
        tmp1 /= 10;
    }
    return num;
}
```