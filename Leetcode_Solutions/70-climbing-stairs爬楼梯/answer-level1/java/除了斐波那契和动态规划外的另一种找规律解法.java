1. 全部1步（走0次两步）的情况为1种；
2. 只走一次两步的情况为n-1种；C 1、n-1
3. 走两次两步的情况为(n-2)*(n-3)/2! C 2、n-2
4. 走三次两步的情况为(n-3)*(n-4)*(n-5)/3! C 3、n-3
5. .
6. .
7. .
8. 走2/n次两步的情况为 C n/2、n/2

```
public int climbStairs(int n) {
        int result = 1;
        long ans = 1;
        for (int i = 1; i <= n / 2; i++) {
            for (int j = 0; j < i; j++) {
                ans = ans * (n - i - j) / (j + 1);
            }
            result += ans;
            ans = 1;
        }
        return result;
    }
```
