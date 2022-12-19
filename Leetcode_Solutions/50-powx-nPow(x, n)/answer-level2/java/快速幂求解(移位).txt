### 解题思路

快速幂: 
- 将n表示为二进制, 利用a^n = a^{2^1} * a^{2^2} + ... 
- 例如n=23, 二级制为10111
    - 3^11 = 3^{2^0 + 2^1 + 2^2 + 2^4} = 3^{2^0} \* 3^{2^1} \* 3^{2^2} \* 3^{2^4}
    - 使用快速幂求解

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        // 使用long保存n, 防止当n=-2^31时溢出
        long pow = n;
        if(pow < 0){
            x = 1 / x;
            pow = -1 * pow;
        }
        double result = 1.0;
        double ans = x;
        while(pow != 0){
            // 当pow二级制对应的位为1时, 需要累乘, 为0时不需要管
            if((pow & 1) != 0){
                result = result * ans;
            }
            ans = ans * ans;
            pow = pow >> 1;
        }
        return result;
    }
}
```