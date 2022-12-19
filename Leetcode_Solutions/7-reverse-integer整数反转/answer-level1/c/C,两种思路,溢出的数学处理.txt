### 解题思路
1. 会溢出的操作前需要判断是否溢出。result = result*10 + (orig%10)
2. 使用long long result保存结果。最后判断result是否在int范围内。(取巧，仅满足题目要求)

### 代码

```c
#define INTMAX (pow(2,31)-1)
#define INTMIN (-pow(2,31))

int reverse(int x){
    int result = 0;
    int orig = x;

    while (orig) {
        if (INTMAX/10 < result || INTMIN/10 > result) return 0;
        result = result*10;
        if ((INTMAX - (orig % 10) < result) || (INTMIN - (orig % 10) > result)) return 0;
        result += (orig % 10);
        orig /= 10;
    }

    return result;
}
```
```c
int reverse(int x){
    long long result = 0;
    int orig = x;

    while (orig) {
        result *= 10;
        result += (orig % 10);
        orig /= 10;
    }

    if (result > (pow(2,31) - 1) ||
        result < -pow(2,31)) {
        return 0;
    }

    return (int)result;
}
```