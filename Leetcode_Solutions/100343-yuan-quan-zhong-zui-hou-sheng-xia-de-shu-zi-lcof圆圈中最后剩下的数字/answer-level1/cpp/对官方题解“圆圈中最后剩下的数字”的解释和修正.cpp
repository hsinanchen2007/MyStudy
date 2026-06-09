1. 关于最先取出的数字，完整表述应为，最先取出序号为(m-1)%n的数字，即第(m-1)%n+1个数字
2. f(n,m)返回的是最终留在数字的序号，即返回的是第f(n,m)+1个数字
```
f(n,m) = ((m-1)%n+1 + f(n-1,m)+1 + 1) % n
       = (m % n + f(n-1, m)) % n
       = (m + f(n-1, m)) % n
```

```
class Solution {
    int f(int n, int m) {
        if (n == 1)
            return 0;
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};
```

