## 基本思路
```
public static int findNthDigit(int n) {
    //base digits
    long base = 9;
    int digits = 1;

    while (n > base * digits) {
        n -= base * digits;
        base *= 10;
        digits++;
    }
    //数字索引
    int index = n % digits;
    if (index == 0) index = digits;
    int number = 1;
    for (int i = 1; i < digits; i++) {
        number *= 10;
    }
    number += index == digits ? n / 3 - 1 : n / 3;
    for (int i = index; i < digits; i++) number /= 10;
    return number % 10;
}
```
## 简化
```
public static int findNthDigitTo(int n) {

    n -= 1;
    for (long digits = 1; digits < 11; ++digits) {
        int first_num = (int) Math.pow(10, digits-1);
        if (n < 9*digits * first_num) {
            String s = String.valueOf(first_num + n / digits);
            int lk = (int) (n%digits);
            String substring = s.substring(lk, lk + 1);
            return Integer.valueOf(substring);
        }
        n-=9*first_num*digits;
    }
    return 0;
}
```
## 说明
- 思路抄的题解c++的，我改了改
- 思路就看题解里面的c++那哥们

