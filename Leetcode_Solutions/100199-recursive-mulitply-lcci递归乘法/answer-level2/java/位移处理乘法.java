### 解题思路

可以把B看成2进制表示，比如B=3(011)，则A\*B=A\*(011)=A\*0 + A\*2 + A\*2\*2，其中A\*2 = A + A。

![image.png](https://pic.leetcode-cn.com/8d39ccca0cdbfdf4b0c32af062e7a7ab431e7ea26667d2193c75573d680467ae-image.png)

### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        if (B == 0) return 0;
        int res = (B & 1) == 1? A : 0;
        int kk = multiply(A, B >>> 1);
        return res + kk + kk;
    }
}
```