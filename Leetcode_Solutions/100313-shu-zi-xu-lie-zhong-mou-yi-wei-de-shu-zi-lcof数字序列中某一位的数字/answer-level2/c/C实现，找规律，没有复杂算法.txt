### 解题思路
此处撰写解题思路

### 代码

```c
int findNthDigit(int n){
    if (n <= 9) return n;
    int base = 1; //先找到对应的是几位数
    while (n > 9 * pow(10, base-1) * base) {
        n -= 9 * pow(10, base-1) *base;
        base++;
    }
    int num = pow(10, base-1) + n / base;  //再找到对应的自然数
    int mod = n % base;  //这个自然数的第i位，范围是1~base
    if (mod == 0) {      //如果余数为0，则表示这个自然数的前一个数
        num = num - 1;
        mod = mod + base;
    }
    int res = 0;
   // printf("%d  %d  %d\n", num, base, mod);
    while (base - mod >= 0) {
        res = num % 10;
        num = num / 10;
        mod++;
    }
    return res;
}
```