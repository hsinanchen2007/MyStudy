### 解题思路
换幂函数换e为底的指数函数

### 代码

```c
int mySqrt(int x){
    double l = exp(0.5 * log(x));
    long long r = (int)l + 1;
    if (r * r > x) return (int)l;
    else return (int)r;
}
/*
int mySqrt(int x){
    long long l, r, num;

    if (x < 2) return x;

    l = 0;
    r = x / 2;
    while (l <= r)
    {
        num = (l + r) / 2;
        if (num * num == x) return num;
        else if (num * num <= x) l++;
        else if (num * num >= x) r--;
    }

    return r;
}
*/
```