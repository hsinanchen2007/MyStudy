### 解题思路

![image.png](https://pic.leetcode-cn.com/6299731bb38137204acc23676e076a671cec93e2e544b1e658e150765920bf20-image.png)


### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        if (n < 10) return n;
        n -= 10;
        int temp = 2;
        while (n >= temp * 9 * Math.pow(10, temp - 1)) {
            n -= temp * 9 * Math.pow(10, temp - 1);
            temp += 1;
        }
        int num = (int) (Math.pow(10, temp - 1)) + n / temp;
        return String.valueOf(num).charAt(n % temp) - '0';
    }
}
```