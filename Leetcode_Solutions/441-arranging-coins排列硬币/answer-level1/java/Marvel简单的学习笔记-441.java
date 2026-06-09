### 解题思路
利用等差数列求和公式来解方程。
由(1+k)*k/2=n，得
(k+1/2)^2=2n+1/4
k=(2n+1/4)^(0.5)-0.5
用Math.sqrt()方法求出k后
向下取整即最终答案，向下取整通过类型转换可以实现，即(int)

### 代码

```java
class Solution {
    public int arrangeCoins(int n) {
        return (int) (Math.sqrt(2.0*n+0.25)-0.5);
    }
}
```