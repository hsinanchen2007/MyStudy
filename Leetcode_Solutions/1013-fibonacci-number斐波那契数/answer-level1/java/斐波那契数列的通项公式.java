[参考链接](https://zhuanlan.zhihu.com/p/26679684)
![CodeCogsEqn.gif](https://pic.leetcode-cn.com/25e4127fce67ae07c8304128c63a42eaf551009f698c98740175716941bdc857-CodeCogsEqn.gif)

```java
    public int fib(int n) {
        if (n <= 1) return n;
        double sqrt5 = Math.sqrt(5);
        double x1 = (1 + sqrt5) / 2;
        double x2 = (1 - sqrt5) / 2;
        return (int) ((Math.pow(x1, n) - Math.pow(x2, n)) / sqrt5);
    }
```