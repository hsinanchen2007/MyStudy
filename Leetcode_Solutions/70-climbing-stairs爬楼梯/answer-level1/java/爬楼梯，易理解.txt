```
public int climbStairs(int n) {
        if(n == 1 || n == 2) {
            return n;
        }

        //从第三阶台阶开始迭代
        int a = 1, temp = 0, b = 2;
        for(int i = 3; i <= n; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return temp;
    }
```
动态规划，使用一个临时变量，比较好理解