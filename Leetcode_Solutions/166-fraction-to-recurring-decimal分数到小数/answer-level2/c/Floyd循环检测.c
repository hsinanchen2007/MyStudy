
看到还没有人发这个方法的题解，上来补充一个。代码写得比较难看，仅提供一个思路。

```
int getLength(long long n)
{
    long long x = n;
    if (x < 0) {
        x *= -1;
    } else if (x == 0) {
        return 1;
    }
    
    int res = 0;
    while (x > 0) {
        x /= 10;
        res++;
    }
    return res;
}

char *handleInteger(long long q)
{
    int len = getLength(q);
    if (q < 0)
        len++;
    char *res = (char *)malloc(len + 1);
    if (res == NULL) {
        return NULL;
    }

    sprintf(res, "%lld", q);
    res[len] = '\0';
    return res;
}

char * fractionToDecimal(int numerator, int denominator) {
    if (denominator == 0) {
        return NULL;
    }
    long long nume = numerator;
    long long deno = denominator;
    int sign = 1;

    if ((nume > 0 && deno < 0) || (nume < 0) && (deno > 0)) {
        sign = -1;
    }
    if (nume < 0) {
        nume *= -1;
    }
    if (deno < 0) {
        deno *= -1;
    }

    long long q = nume / deno;
    long long r = nume % deno;
    int lenInteger = getLength(q);
    int totalLen = 0;
    char *res = NULL;
    int lenFraction = 0;
    int lenCircle = 0;
    int i, r1, r2;
    
    // 整数的情况单独处理
    if (r == 0) {
        return handleInteger(q * sign);
    }

    r1 = r; // 单倍速指针
    r2 = r; // 双倍速指针

    // 两个指针第一次相遇
    do {
        r1 = (int)(((long long)r1 * 10) % deno);
        r2 = (int)(((long long)r2 * 10) % deno);
        r2 = (int)(((long long)r2 * 10) % deno);
    } while (r1 != r2);
    
    // 确定循环节长度
    int isCircle = 0;
    do {
        r1 = (int)(((long long)r1 * 10) % deno);
        lenCircle++;
    } while(r1 != r2);
    if (r1 != 0) {
        isCircle = 1;
    }
    
    // 确定非循环的小数部分长度
    r1 = r;
    while (r1 != r2) {
        r1 = (int)(((long long)r1 * 10) % deno);
        r2 = (int)(((long long)r2 * 10) % deno);
        lenFraction++;
    }
    
    // 计算总长度
    totalLen += (lenInteger + 1 + lenFraction);
    if (sign < 0) {
        totalLen++;
    }
    if (isCircle) {
        totalLen += (lenCircle + 2);
    }
    
    res = (char *)malloc(totalLen + 1);
    if (res == NULL) {
        return NULL;
    }
    
    // 输出
    i = 0;
    if (sign < 0) {
        i += sprintf(res + i, "%c", '-');
    }
    i += sprintf(res + i, "%d", q);
    i += sprintf(res + i, "%c", '.');
    for (int j = 0; j < lenFraction; j++) {
        i += sprintf(res + i, "%d", (int)(((long long)r * 10) / deno));
        r = (int)(((long long)r * 10) % deno);
    }
    if (isCircle) {
        i += sprintf(res + i, "%c", '(');
        for (int j = 0; j < lenCircle; j++) {
            i += sprintf(res + i, "%d", (int)(((long long)r * 10) / deno));
            r = (int)(((long long)r * 10) % deno);
        }
        i += sprintf(res + i, "%c", ')');
    }
    res[i] = '\0';
    return res;
}
```
