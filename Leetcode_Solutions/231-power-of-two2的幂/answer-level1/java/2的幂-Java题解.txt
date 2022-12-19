### 解题思路
方法1：循环：n模2==0，即为偶数，n除2。最后2次幂的数一定为2^0 = 1的结果，否则false
方法2：2次幂数n 与 n-1的逻辑与运算必定为0（小技巧记忆，还可以判断二进制数中1的个数），满足即为2次幂数

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        //方法1
        // if(n <= 0) return false;
        // while(n % 2 == 0) n /= 2;
        // return n == 1;

        //方法2
        return n > 0 && (n & (n - 1)) == 0;
    }
}
```