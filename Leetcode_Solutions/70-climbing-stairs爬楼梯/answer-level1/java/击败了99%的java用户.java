## 题目分析
其实这个可以看做一个斐波那锲数问题。因为每次只能跳一步或者两步。所以a[n]=a[n-1]+a[n-2];
## 代码
```java
public int climbStairs(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        int res = 0;
        for (int i = 2; i < n; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
```