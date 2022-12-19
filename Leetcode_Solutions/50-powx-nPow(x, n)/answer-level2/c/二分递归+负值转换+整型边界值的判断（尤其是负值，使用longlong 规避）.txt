### 解题思路
此处撰写解题思路

### 代码

```c
double helper(double x, long long n)
{
    if (n < 0) {
        x = 1/x;
        n = -n;
    }

    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return x;
    }

    double half = helper(x, n/2);

    if (n % 2 == 0) {
        return half * half;
    } else {
        return half * half * x;
    }
}
double myPow(double x, int n){
   return helper(x, n);
}
```