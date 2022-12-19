### 解题思路
    1、递归
    2、循环
    3、数学

### 代码

```java
class Solution {
    public int fib(int N) {
        if (n <= 1) {
            return n;
        }
        return fib1(n - 1) + fib1(n - 2);
    }
}
```

```java
class Solution {
    public int fib(int N) {
        int first = 0;
        int second = 1;
        if (n <= 1) {
            return n;
        }
        for (int i = 0; i < n - 1; i++) {
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
}
```

```java
class Solution {
    public int fib(int N) {
    double c = Math.sqrt(5);
    return (int) ((Math.pow((1 + c) / 2, N) - Math.pow((1 - c) / 2, N)) / c);
    }
}
```