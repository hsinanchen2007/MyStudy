### 解题思路
直接按照官方解答方法三的代码是无法通过编译的，需要自己定义epsilon值（epsilon似乎是一个自定义的值，而不是某个基类自带的）。而且epsilon要设置的足够足够小，我之前有一版设置epsilon为10e-7没有通过，设置成10e-11才可以。


### 代码

```java
class Solution {
    public boolean isPowerOfThree(int n) {
        // 非原创 换底公式 + 使用epsilon弥补六位浮点数的误差
        final double epsilon = 0.00000000001;
        return (Math.log(n) / Math.log(3) + epsilon) % 1 <= 2 * epsilon;
    }
}
```