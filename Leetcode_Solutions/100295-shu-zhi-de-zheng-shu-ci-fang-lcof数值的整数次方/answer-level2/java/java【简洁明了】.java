![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/92f48b9f74532887705e378a959161f6c03d6e8e088115014656d216cc7d306c-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if (x == 1.0) return 1.0;
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n < 0) return 1.0 / (myPow(x, -n-1)*x);
        if (n % 2 == 1) {//n为奇数
            double tmp = myPow(x, n / 2);
            return tmp * tmp * x;
        } else {//n为偶数
            double tmp = myPow(x, n / 2);
            return tmp * tmp;
        }
    }
}
```