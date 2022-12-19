### 解题思路
注意考虑n为负数的情况。
n为负数可以将指数考虑为正数，最后取倒数即可。
n为负数对其取相反数的时候需要考虑溢出的情况，因此需要用一个long型存储n对应的绝对值。

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }
        if (n == 1) {
            return x;
        }

        boolean flag = false;
        long ex = n;
        if (n < 0) {
            ex *= -1;
            flag = true;
        }
        double val = 1;
        while (ex > 0) {
            if ((ex % 2) == 1) {
                val *= x;
            }
            ex >>= 1;
            x *= x;
        }

        return flag ? 1 / val : val;
    }
}
```