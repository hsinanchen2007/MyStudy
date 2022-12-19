### 解题思路
1、先排除下特殊的情况：被除数为INT_MIN，直接返回，因为这种情况取绝对值后超出范围；除数为0；
2、不能以除数的步伐进行增加，会超时，每次两倍的步伐增加，步伐太大的时候，重新从1步开始；
3、为了防止乘2超出范围，使用long long的数据类型；

### 代码

```c
int divide(int dividend, int divisor){
    int flag = 1;
    int ans = 0;
    long long unsignDivid = (long long)llabs(dividend);
    long long unsignDivis = (long long)llabs(divisor);

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }
    if (divisor == 0) {
        return 0;
    }
    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
        flag = -1;
    }
    while (unsignDivid >= unsignDivis) {
        long long scop = unsignDivis;
        int p = 1;
        while (unsignDivid >= scop << 1) {
            scop = scop << 1;
            p = (p << 1);
        }
        unsignDivid -= scop;
        ans += p;
    }

    return flag == -1 ? -ans : ans;
}
```