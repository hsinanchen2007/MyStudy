直接用递归的话会超时，所以应该减小递归的次数，对于通项公式进一步推导

T(n+3) = T(n+2) + T(n+1) +T(n+0)
T(n+4) = T(n+3) + T(n+2) + T(n+1)
两者相减
T(n+4) - T(n+3) = T(n+3) - T(n)
所以T(n) = 2T(n-1) - T(n+4)

```
    public int tribonacci(int n) {
        switch (n) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 1;
            case 3:
                return 2;
            case 4:
                return 4;
            default:
                return  2 * tribonacci(n - 1) - tribonacci(n + 4);
        }
    }
```

